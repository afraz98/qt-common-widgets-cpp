#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include "detachabletabwidget.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    DetachableTabWidget tabWidget;

    QLabel* tab1 = new QLabel("Test Widget 1");
    tabWidget.addTab(tab1, "Tab1");

    QLabel* tab2 = new QLabel("Test Widget 2");
    tabWidget.addTab(tab2, "Tab2");

    QLabel* tab3 = new QLabel("Test Widget 3");
    tabWidget.addTab(tab3, "Tab3");

    tabWidget.show();
    mainWindow.setCentralWidget(&tabWidget);
    mainWindow.show();

    return app.exec();
}
