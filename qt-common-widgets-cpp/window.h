#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLabel>

#include "detachabletabwidget.h"
#include "detachedtabwidget.h"

class Window : public QWidget {
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

public slots:
    void createDetachedTabWindow(QWidget *detachedTab);

private:
    void create();

    void connect();

    QVBoxLayout* outermost_layout;

    DetachableTabWidget* tabs;


};


#endif // WINDOW_H
