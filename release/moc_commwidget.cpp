/****************************************************************************
** Meta object code from reading C++ file 'commwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../commwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CommWidget_t {
    QByteArrayData data[12];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommWidget_t qt_meta_stringdata_CommWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CommWidget"
QT_MOC_LITERAL(1, 11, 7), // "refresh"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "invocChange"
QT_MOC_LITERAL(4, 32, 6), // "prefix"
QT_MOC_LITERAL(5, 39, 6), // "remove"
QT_MOC_LITERAL(6, 46, 9), // "unitIndex"
QT_MOC_LITERAL(7, 56, 7), // "addUnit"
QT_MOC_LITERAL(8, 64, 10), // "removeUnit"
QT_MOC_LITERAL(9, 75, 18), // "requestRefreshHost"
QT_MOC_LITERAL(10, 94, 21), // "handleCommanderChange"
QT_MOC_LITERAL(11, 116, 19) // "requestRefreshInvoc"

    },
    "CommWidget\0refresh\0\0invocChange\0prefix\0"
    "remove\0unitIndex\0addUnit\0removeUnit\0"
    "requestRefreshHost\0handleCommanderChange\0"
    "requestRefreshInvoc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    3,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   57,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,
      10,    0,   60,    2, 0x08 /* Private */,
      11,    3,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Int,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Int,    4,    5,    6,

       0        // eod
};

void CommWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CommWidget *_t = static_cast<CommWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refresh(); break;
        case 1: _t->invocChange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->addUnit(); break;
        case 3: _t->removeUnit(); break;
        case 4: _t->requestRefreshHost(); break;
        case 5: _t->handleCommanderChange(); break;
        case 6: _t->requestRefreshInvoc((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CommWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommWidget::refresh)) {
                *result = 0;
            }
        }
        {
            typedef void (CommWidget::*_t)(QString , bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommWidget::invocChange)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CommWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CommWidget.data,
      qt_meta_data_CommWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CommWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CommWidget.stringdata0))
        return static_cast<void*>(const_cast< CommWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CommWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CommWidget::refresh()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CommWidget::invocChange(QString _t1, bool _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
