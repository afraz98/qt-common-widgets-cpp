// detachabletabbar.cpp
#include "detachabletabbar.h"
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>

DetachableTabBar::DetachableTabBar(QWidget *parent)
    : QTabBar(parent), draggingTabIndex(-1)
{
    setAcceptDrops(true);
}

void DetachableTabBar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        draggingTabIndex = tabAt(event->pos());
    }

    QTabBar::mousePressEvent(event);
}

void DetachableTabBar::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton && draggingTabIndex != -1) {
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;
        mimeData->setData("application/x-tab-index", QByteArray::number(draggingTabIndex));
        drag->setMimeData(mimeData);

        // Start the drag and drop operation
        drag->exec(Qt::MoveAction);
    }

    QTabBar::mouseMoveEvent(event);
}

void DetachableTabBar::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        draggingTabIndex = -1;
    }

    QTabBar::mouseReleaseEvent(event);
}

void DetachableTabBar::updateTabCloseButton(int tabIndex)
{
    // Implement the logic to update the appearance of the close button for the specified tab index
    // You might need to customize this based on your requirements
    // ...
}
