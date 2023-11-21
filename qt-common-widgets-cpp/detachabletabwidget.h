// detachabletabwidget.h
#ifndef DETACHABLETABWIDGET_H
#define DETACHABLETABWIDGET_H

#include <QTabWidget>

class DetachableTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    DetachableTabWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;

signals:
    void tabDetached(QWidget* detachedTab);

private:
    void detachTab(int index);

    QPoint dragStartPosition;
};

#endif // DETACHABLETABWIDGET_H
