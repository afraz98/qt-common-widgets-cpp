// detachabletabwidget.h
#ifndef DETACHABLETABWIDGET_H
#define DETACHABLETABWIDGET_H

#include <QTabWidget>
#include <QTabBar>
#include "detachedtab.h"

class DetachedTab;

class DetachableTabWidget : public QTabWidget {
    Q_OBJECT

public:
    DetachableTabWidget(QWidget* parent = nullptr);

    ~DetachableTabWidget();

    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    class TabBar;
    TabBar* tabBar;
    QHash<QString, DetachedTab*> detachedTabs;

    void closeDetachedTabs();

private slots:
    void detachTab(int index, const QPoint& point);
    void moveTab(int fromIndex, int toIndex);
    void attachTab(QWidget* contentWidget, const QString& name, const QIcon& icon, int insertAt = -1);
    void removeTabByName(const QString& name);
    void detachedTabDrop(const QString& name, int index, const QPoint& dropPos);
};


class DetachableTabWidget::TabBar : public QTabBar {
    Q_OBJECT
public:
    TabBar(DetachableTabWidget* parent);

    ~TabBar();

    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;

signals:
    void onDetachTabSignal(int index, const QPoint& pos);
    void onMoveTabSignal(int fromIndex, int toIndex);
    void detachedTabDropSignal(const QString& name, int index, const QPoint& dropPos);

private:
    DetachableTabWidget* parentTabWidget;
    QPoint dragStartPosition;
    QPoint dragDropPosition;
    bool dragInitiated;
    QCursor mouseCursor;

private slots:
    void detachedTabDrop(const QString& name, const QPoint& dropPos);
};


#endif // DETACHABLETABWIDGET_H
