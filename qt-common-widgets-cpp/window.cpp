#include "window.h"
#include "detachabletabwidget.h"
#include "detachedtabwidget.h"

#include <QDebug>
#include <QVBoxLayout>
#include <QLabel>
#include <iostream>


Window::Window(QWidget *parent) : QWidget(parent){
    create();
    connect();
}

Window::~Window(){}

void Window::create(){
    outermost_layout = new QVBoxLayout(this);

    tabs = new DetachableTabWidget(this);
    tabs->addTab(new QLabel("Main Tab"), "Main");
    tabs->addTab(new QLabel("Secondary Tab"), "Secondary");
    tabs->addTab(new QLabel("Tertiary Tab"), "Tertiary");

    outermost_layout->addWidget(tabs);
    setLayout(outermost_layout);
}

void Window::connect(){
    QObject::connect(tabs, &DetachableTabWidget::tabDetached, this, &Window::createDetachedTabWindow, Qt::DirectConnection);
    qDebug() << "Connection established";
}

void Window::createDetachedTabWindow(QWidget *detachedTab){
    try {
        qDebug() << "Tab detached!";
        DetachedTabWidget *detachedTabWindow = new DetachedTabWidget(this);
        detachedTabWindow->addDetachedTab(detachedTab, "Detached Tab", QIcon());
        detachedTabWindow->show();
        qDebug() << "Detached tab window created!";
    } catch (const std::exception& e) {
        qDebug() << "Exception in createDetachedTabWindow: " << e.what();
    }
}
