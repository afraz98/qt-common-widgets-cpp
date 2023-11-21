#ifndef DETACHEDTAB_H
#define DETACHEDTAB_H

#include "detachabletabwidget.h"
#include <QMainWindow>
#include <QEvent>

class DetachableTabWidget;

class DetachedTab : public QMainWindow {
    Q_OBJECT
public:
    DetachedTab(const QString& name, QWidget* contentWidget, DetachableTabWidget* parent);

    ~DetachedTab();

    QWidget* contentWidget;

    QIcon windowIcon;

    class WindowDropFilter : public QObject {
        Q_OBJECT
    public:
        WindowDropFilter(DetachedTab* parent);
        QEvent::Type lastEventType;

    signals:
        void onDropSignal(const QPoint& dropPos);

    protected:
        bool eventFilter(QObject* obj, QEvent* event) override;

    private:
        DetachedTab* parentTab;
    };

    WindowDropFilter* windowDropFilter;

signals:
    void onCloseSignal(QWidget* contentWidget, const QString& name, const QIcon& icon);
    void onDropSignal(const QPoint& dropPos);

public slots:
    void onCloseSlot(QWidget* contentWidget, const QString& name, const QIcon& icon);

protected:
    void closeEvent(QCloseEvent* event) override;
    bool eventFilter(QObject* obj, QEvent* event) override;

private:
    QString tabName;


private slots:
    void windowDropSlot(const QPoint& dropPos);
};

#endif // DETACHEDTAB_H
