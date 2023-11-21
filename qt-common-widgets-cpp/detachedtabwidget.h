// detachedtabwidget.h
#ifndef DETACHEDTABWIDGET_H
#define DETACHEDTABWIDGET_H

#include <QTabWidget>
#include <QVBoxLayout>

class DetachedTabWidget : public QWidget {
    Q_OBJECT

public:
    DetachedTabWidget(QWidget *parent = nullptr);
    void addDetachedTab(QWidget *tab, const QString &text, const QIcon &icon);

private:
    QTabWidget *tabWidget;
};

#endif // DETACHEDTABWIDGET_H
