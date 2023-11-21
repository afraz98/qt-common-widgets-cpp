/****************************************************************************
** Meta object code from reading C++ file 'detachabletabwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt-common-widgets-cpp/detachabletabwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'detachabletabwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DetachableTabWidget_t {
    QByteArrayData data[17];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DetachableTabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DetachableTabWidget_t qt_meta_stringdata_DetachableTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "DetachableTabWidget"
QT_MOC_LITERAL(1, 20, 9), // "detachTab"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "index"
QT_MOC_LITERAL(4, 37, 5), // "point"
QT_MOC_LITERAL(5, 43, 7), // "moveTab"
QT_MOC_LITERAL(6, 51, 9), // "fromIndex"
QT_MOC_LITERAL(7, 61, 7), // "toIndex"
QT_MOC_LITERAL(8, 69, 9), // "attachTab"
QT_MOC_LITERAL(9, 79, 8), // "QWidget*"
QT_MOC_LITERAL(10, 88, 13), // "contentWidget"
QT_MOC_LITERAL(11, 102, 4), // "name"
QT_MOC_LITERAL(12, 107, 4), // "icon"
QT_MOC_LITERAL(13, 112, 8), // "insertAt"
QT_MOC_LITERAL(14, 121, 15), // "removeTabByName"
QT_MOC_LITERAL(15, 137, 15), // "detachedTabDrop"
QT_MOC_LITERAL(16, 153, 7) // "dropPos"

    },
    "DetachableTabWidget\0detachTab\0\0index\0"
    "point\0moveTab\0fromIndex\0toIndex\0"
    "attachTab\0QWidget*\0contentWidget\0name\0"
    "icon\0insertAt\0removeTabByName\0"
    "detachedTabDrop\0dropPos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DetachableTabWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x08 /* Private */,
       5,    2,   49,    2, 0x08 /* Private */,
       8,    4,   54,    2, 0x08 /* Private */,
       8,    3,   63,    2, 0x28 /* Private | MethodCloned */,
      14,    1,   70,    2, 0x08 /* Private */,
      15,    3,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QIcon, QMetaType::Int,   10,   11,   12,   13,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QIcon,   10,   11,   12,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QPoint,   11,    3,   16,

       0        // eod
};

void DetachableTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DetachableTabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->detachTab((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 1: _t->moveTab((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->attachTab((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QIcon(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->attachTab((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QIcon(*)>(_a[3]))); break;
        case 4: _t->removeTabByName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->detachedTabDrop((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QPoint(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DetachableTabWidget::staticMetaObject = { {
    &QTabWidget::staticMetaObject,
    qt_meta_stringdata_DetachableTabWidget.data,
    qt_meta_data_DetachableTabWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DetachableTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DetachableTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DetachableTabWidget.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int DetachableTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
struct qt_meta_stringdata_DetachableTabWidget__TabBar_t {
    QByteArrayData data[12];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DetachableTabWidget__TabBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DetachableTabWidget__TabBar_t qt_meta_stringdata_DetachableTabWidget__TabBar = {
    {
QT_MOC_LITERAL(0, 0, 27), // "DetachableTabWidget::TabBar"
QT_MOC_LITERAL(1, 28, 17), // "onDetachTabSignal"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 5), // "index"
QT_MOC_LITERAL(4, 53, 3), // "pos"
QT_MOC_LITERAL(5, 57, 15), // "onMoveTabSignal"
QT_MOC_LITERAL(6, 73, 9), // "fromIndex"
QT_MOC_LITERAL(7, 83, 7), // "toIndex"
QT_MOC_LITERAL(8, 91, 21), // "detachedTabDropSignal"
QT_MOC_LITERAL(9, 113, 4), // "name"
QT_MOC_LITERAL(10, 118, 7), // "dropPos"
QT_MOC_LITERAL(11, 126, 15) // "detachedTabDrop"

    },
    "DetachableTabWidget::TabBar\0"
    "onDetachTabSignal\0\0index\0pos\0"
    "onMoveTabSignal\0fromIndex\0toIndex\0"
    "detachedTabDropSignal\0name\0dropPos\0"
    "detachedTabDrop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DetachableTabWidget__TabBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    2,   39,    2, 0x06 /* Public */,
       8,    3,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QPoint,    9,    3,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QPoint,    9,   10,

       0        // eod
};

void DetachableTabWidget::TabBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TabBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onDetachTabSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 1: _t->onMoveTabSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->detachedTabDropSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QPoint(*)>(_a[3]))); break;
        case 3: _t->detachedTabDrop((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TabBar::*)(int , const QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TabBar::onDetachTabSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TabBar::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TabBar::onMoveTabSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TabBar::*)(const QString & , int , const QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TabBar::detachedTabDropSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DetachableTabWidget::TabBar::staticMetaObject = { {
    &QTabBar::staticMetaObject,
    qt_meta_stringdata_DetachableTabWidget__TabBar.data,
    qt_meta_data_DetachableTabWidget__TabBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DetachableTabWidget::TabBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DetachableTabWidget::TabBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DetachableTabWidget__TabBar.stringdata0))
        return static_cast<void*>(this);
    return QTabBar::qt_metacast(_clname);
}

int DetachableTabWidget::TabBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DetachableTabWidget::TabBar::onDetachTabSignal(int _t1, const QPoint & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DetachableTabWidget::TabBar::onMoveTabSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DetachableTabWidget::TabBar::detachedTabDropSignal(const QString & _t1, int _t2, const QPoint & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
