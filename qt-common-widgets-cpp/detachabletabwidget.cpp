
#include "detachabletabwidget.h"
#include "detachedtab.h"

#include <QMouseEvent>
#include <QCoreApplication>
#include <QApplication>
#include <QPainter>
#include <QDrag>
#include <QMimeData>

DetachableTabWidget::DetachableTabWidget(QWidget* parent) : QTabWidget(parent), tabBar(new TabBar(this)) {
    setTabBar(tabBar);
    tabBar->setAcceptDrops(true);
    tabBar->setElideMode(Qt::ElideRight);
    tabBar->setSelectionBehaviorOnRemove(QTabBar::SelectLeftTab);

    tabBar->installEventFilter(this);

    connect(tabBar, &TabBar::onDetachTabSignal, this, &DetachableTabWidget::detachTab);
    connect(tabBar, &TabBar::onMoveTabSignal, this, &DetachableTabWidget::moveTab);
    connect(tabBar, &TabBar::detachedTabDropSignal, this, &DetachableTabWidget::detachedTabDrop);

    connect(qApp, &QCoreApplication::aboutToQuit, this, &DetachableTabWidget::closeDetachedTabs);
}

DetachableTabWidget::~DetachableTabWidget(){}

void DetachableTabWidget::mouseDoubleClickEvent(QMouseEvent* event) {
    tabBar->mouseDoubleClickEvent(event);
}

void DetachableTabWidget::mousePressEvent(QMouseEvent* event) {
    tabBar->mousePressEvent(event);
}

void DetachableTabWidget::mouseMoveEvent(QMouseEvent* event) {
    tabBar->mouseMoveEvent(event);
}

DetachableTabWidget::TabBar::TabBar(DetachableTabWidget* parent) : QTabBar(parent), parentTabWidget(parent), dragStartPosition(QPoint()), dragDropPosition(QPoint()), dragInitiated(false), mouseCursor() {}

DetachableTabWidget::TabBar::~TabBar(){}

void DetachableTabWidget::TabBar::mouseDoubleClickEvent(QMouseEvent* event){
    event->accept();
    emit onDetachTabSignal(tabAt(event->pos()), QCursor::pos());
}

void DetachableTabWidget::TabBar::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        dragStartPosition = event->pos();
    }

    dragDropPosition.setX(0);
    dragDropPosition.setY(0);

    dragInitiated = false;

    QTabBar::mousePressEvent(event);
}

void DetachableTabWidget::TabBar::mouseMoveEvent(QMouseEvent* event) {
    if (!dragStartPosition.isNull() && (event->pos() - dragStartPosition).manhattanLength() < QApplication::startDragDistance()) {
        dragInitiated = true;
    }

    if (((event->buttons() & Qt::LeftButton)) && dragInitiated) {
        QMouseEvent finishMoveEvent(QEvent::MouseMove, event->pos(), Qt::NoButton, Qt::NoButton, Qt::NoModifier);
        QTabBar::mouseMoveEvent(&finishMoveEvent);

        QDrag drag(this);
        QMimeData mimeData;
        mimeData.setData("action", "application/tab-detach");
        drag.setMimeData(&mimeData);

        QPixmap pixmap = QPixmap::grabWindow(parentTabWidget->currentWidget()->winId());
        QPixmap targetPixmap(pixmap.size());
        targetPixmap.fill(Qt::transparent);
        QPainter painter(&targetPixmap);
        painter.setOpacity(0.85);
        painter.drawPixmap(0, 0, pixmap);
        painter.end();
        drag.setPixmap(targetPixmap);

        int dropAction = drag.exec(Qt::MoveAction | Qt::CopyAction);

        if (dragDropPosition.x() != 0 && dragDropPosition.y() != 0) {
            dropAction = Qt::MoveAction;
        }

        if (dropAction == Qt::IgnoreAction) {
            event->accept();
            emit onDetachTabSignal(tabAt(dragStartPosition), mouseCursor.pos());
        } else if (dropAction == Qt::MoveAction) {
            if (!dragDropPosition.isNull()) {
                event->accept();
                emit onMoveTabSignal(tabAt(dragStartPosition), tabAt(dragDropPosition));
            }
        }
    } else {
        QTabBar::mouseMoveEvent(event);
    }
}

void DetachableTabWidget::TabBar::dragEnterEvent(QDragEnterEvent* event) {
    const QMimeData* mimeData = event->mimeData();
    QStringList formats = mimeData->formats();

    if (formats.contains("action") && mimeData->data("action") == "application/tab-detach") {
        event->acceptProposedAction();
    }

    QTabBar::dragMoveEvent(event);
}

void DetachableTabWidget::TabBar::dropEvent(QDropEvent* event) {
    dragDropPosition = event->pos();
    QTabBar::dropEvent(event);
}

void DetachableTabWidget::TabBar::detachedTabDrop(const QString& name, const QPoint& dropPos) {
    QPoint tabDropPos = mapFromGlobal(dropPos);
    int index = tabAt(tabDropPos);
    emit detachedTabDropSignal(name, index, dropPos);
}

void DetachableTabWidget::detachTab(int index, const QPoint& point) {
    QWidget* tab = widget(index);
    QIcon icon = tabBar->tabIcon(index);
    QString text = tabBar->tabText(index);

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << text << icon << index;

    QMimeData* mimeData = new QMimeData;
    mimeData->setData("application/x-tab", itemData);

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(tab->grab());
    drag->exec(Qt::MoveAction);

    DetachedTab* detachedTab = new DetachedTab(text, tab, this);
    detachedTab->setWindowIcon(icon);
    detachedTab->move(point);
    detachedTab->show();

    detachedTabs[text] = detachedTab;
}

void DetachableTabWidget::moveTab(int fromIndex, int toIndex) {
    QWidget* widget = this->widget(fromIndex);
    QIcon icon = tabBar->tabIcon(fromIndex);
    QString text = tabBar->tabText(fromIndex);

    removeTab(fromIndex);
    insertTab(toIndex, widget, icon, text);
    setCurrentIndex(toIndex);
}

void DetachableTabWidget::attachTab(QWidget* contentWidget, const QString& name, const QIcon& icon, int insertAt) {
    contentWidget->setParent(this);

    delete detachedTabs.value(name);
    detachedTabs.remove(name);

    QIcon tabIcon = (icon.isNull()) ? windowIcon() : icon;

    if (insertAt == -1) {
        insertAt = addTab(contentWidget, tabIcon, name);
    } else {
        insertTab(insertAt, contentWidget, tabIcon, name);
    }

    setCurrentIndex(insertAt);
}

void DetachableTabWidget::removeTabByName(const QString& name) {
    bool attached = false;
    for (int index = 0; index < count(); ++index) {
        if (name == tabBar->tabText(index)) {
            removeTab(index);
            attached = true;
            break;
        }
    }

    if (!attached) {
        DetachedTab* detachedTab = detachedTabs.value(name);
        if (detachedTab) {
            detachedTab->close();
            delete detachedTab;
            detachedTabs.remove(name);
        }
    }
}

void DetachableTabWidget::detachedTabDrop(const QString& name, int index, const QPoint& dropPos) {
    if (index > -1) {
        QWidget* contentWidget = detachedTabs[name]->contentWidget;
        QIcon icon = detachedTabs[name]->windowIcon;

        detachedTabs[name]->close();
        delete detachedTabs[name];

        attachTab(contentWidget, name, icon, index);
    } else {
        QPoint tabDropPos = tabBar->mapFromGlobal(dropPos);
        if (tabBar->rect().contains(tabDropPos)) {
            if (tabDropPos.y() < tabBar->height() || count() == 0) {
                detachedTabs[name]->close();
                delete detachedTabs[name];
            }
        }
    }
}

void DetachableTabWidget::closeDetachedTabs() {
    QList<DetachedTab*> detachedTabList = detachedTabs.values();
    for (DetachedTab* detachedTab : detachedTabList) {
        detachedTab->close();
        delete detachedTab;
    }
}
