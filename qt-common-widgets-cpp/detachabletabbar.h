// detachabletabbar.h
#ifndef DETACHABLETABBAR_H
#define DETACHABLETABBAR_H

#include <QTabBar>

class DetachableTabBar : public QTabBar
{
    Q_OBJECT

public:
    explicit DetachableTabBar(QWidget *parent = nullptr);

    void updateTabCloseButton(int tabIndex);

signals:
    void tabCloseRequested(int index);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int draggingTabIndex;
};

#endif // DETACHABLETABBAR_H
