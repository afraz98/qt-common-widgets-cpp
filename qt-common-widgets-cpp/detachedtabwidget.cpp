// detachedtabwidget.cpp
#include "detachedtabwidget.h"
#include <QTabWidget>
#include <QVBoxLayout>

DetachedTabWidget::DetachedTabWidget(QWidget *parent) : QWidget(parent)
{
    tabWidget = new QTabWidget(this);
    // setCentralWidget(tabWidget);
}

void DetachedTabWidget::addDetachedTab(QWidget *tab, const QString &text, const QIcon &icon)
{
    tabWidget->addTab(tab, icon, text);
    tabWidget->setCurrentWidget(tab);
    // setWindowTitle(text);
}
