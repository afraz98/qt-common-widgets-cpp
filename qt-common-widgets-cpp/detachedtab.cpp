#include "detachedtab.h"

#include <QEvent>
#include <QMouseEvent>

DetachedTab::DetachedTab(const QString& name, QWidget* contentWidget, DetachableTabWidget* parent) : QMainWindow(nullptr), contentWidget(contentWidget), tabName(name), windowIcon(parent->windowIcon()) {
    setObjectName(name);
    setWindowTitle(name);
    setCentralWidget(contentWidget);
    contentWidget->show();

    windowDropFilter = new WindowDropFilter(this);
    installEventFilter(windowDropFilter);
    connect(windowDropFilter, &WindowDropFilter::onDropSignal, this, &DetachedTab::windowDropSlot);
    connect(this, &DetachedTab::onCloseSignal, this, &DetachedTab::onCloseSlot);
}

DetachedTab::~DetachedTab(){}

void DetachedTab::onCloseSlot(QWidget* contentWidget, const QString& name, const QIcon& icon) {
    // Handle the closure of the detached tab
    emit onCloseSignal(contentWidget, name, icon);
    // Optionally, you can disconnect the signal here if needed.
}

void DetachedTab::closeEvent(QCloseEvent* event) {
    emit onCloseSignal(this->contentWidget, tabName, windowIcon);
    event->accept();
}

bool DetachedTab::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::NonClientAreaMouseMove && windowDropFilter->lastEventType == QEvent::Move) {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        emit onDropSignal(mouseEvent->globalPos());
        windowDropFilter->lastEventType = event->type();
        return true;
    } else {
        windowDropFilter->lastEventType = event->type();
        return false;
    }
}

DetachedTab::WindowDropFilter::WindowDropFilter(DetachedTab* parent) : QObject(parent), parentTab(parent), lastEventType(QEvent::None) {}

bool DetachedTab::WindowDropFilter::eventFilter(QObject* obj, QEvent* event) {
    Q_UNUSED(obj);
    if (lastEventType == QEvent::Move && event->type() == 173) {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        emit onDropSignal(mouseEvent->globalPos());
        lastEventType = event->type();
        return true;
    } else {
        lastEventType = event->type();
        return false;
    }
}
