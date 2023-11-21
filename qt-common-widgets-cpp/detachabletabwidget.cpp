// detachabletabwidget.cpp
#include "detachabletabwidget.h"
#include "detachedtabwidget.h"

#include <iostream>

#include <QDebug>
#include <QMimeData>
#include <QMouseEvent>
#include <QDrag>
#include <QApplication>
#include <QTabBar>

DetachableTabWidget::DetachableTabWidget(QWidget *parent) : QTabWidget(parent) {
    setTabsClosable(true);
    setMovable(true);
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAcceptDrops(true);
}

void DetachableTabWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragStartPosition = event->pos();
    }

    QTabWidget::mousePressEvent(event);
}

void DetachableTabWidget::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && (event->pos() - dragStartPosition).manhattanLength() > QApplication::startDragDistance()) {
        int tabIndex = tabBar()->tabAt(dragStartPosition);
        qDebug() << "Mouse Move Event - Tab Index:" << tabIndex;
        if (tabIndex != -1) {
            detachTab(tabIndex);
        }
    }

    QTabWidget::mouseMoveEvent(event);
}

void DetachableTabWidget::dropEvent(QDropEvent *event) {
    qDebug() << "Drop Event Called";

    const QMimeData *mimeData = event->mimeData();

    if (mimeData->hasFormat("application/x-tab")) {
        QByteArray itemData = mimeData->data("application/x-tab");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QString text;
        QIcon icon;
        int tabIndex;

        dataStream >> text >> icon >> tabIndex;

        QWidget *detachedTab = widget(tabIndex);
        removeTab(tabIndex);

        event->setDropAction(Qt::MoveAction);
        event->accept();

        DetachedTabWidget *detachedTabWidget = new DetachedTabWidget;
        detachedTabWidget->addDetachedTab(detachedTab, text, icon);
        detachedTabWidget->show();

        emit tabDetached(detachedTab);
        qDebug() << "Drop Event - Tab Detached and Signal Emitted.";
    }

    QTabWidget::dropEvent(event);
}

void DetachableTabWidget::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << "Drag Enter Event Called";

    const QMimeData *mimeData = event->mimeData();

    if (mimeData->hasFormat("application/x-tab")) {
        event->acceptProposedAction();
        qDebug() << "Drag Enter Event - Tab Accepted.";
    }

    QTabWidget::dragEnterEvent(event);
}

void DetachableTabWidget::detachTab(int index)
{
    QWidget *tab = widget(index);
    QIcon icon = tabBar()->tabIcon(index);
    QString text = tabBar()->tabText(index);

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << text << icon << index;

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-tab", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(tab->grab());
    drag->exec(Qt::MoveAction);

    DetachedTabWidget *detachedTabWidget = new DetachedTabWidget;
    detachedTabWidget->addDetachedTab(tab, tabBar()->tabText(index), tabBar()->tabIcon(index));
    detachedTabWidget->show();

    // Emit a signal for handling the detached tab
    emit tabDetached(tab);
    qDebug() << "Tab detached and signal emitted.";
}
