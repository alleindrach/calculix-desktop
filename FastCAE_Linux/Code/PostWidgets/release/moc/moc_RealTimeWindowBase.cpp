/****************************************************************************
** Meta object code from reading C++ file 'RealTimeWindowBase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RealTimeWindowBase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RealTimeWindowBase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Post__RealTimeWindowBase_t {
    QByteArrayData data[9];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Post__RealTimeWindowBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Post__RealTimeWindowBase_t qt_meta_stringdata_Post__RealTimeWindowBase = {
    {
QT_MOC_LITERAL(0, 0, 24), // "Post::RealTimeWindowBase"
QT_MOC_LITERAL(1, 25, 11), // "closeWindow"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 25), // "Post::RealTimeWindowBase*"
QT_MOC_LITERAL(4, 64, 1), // "w"
QT_MOC_LITERAL(5, 66, 10), // "updatePlot"
QT_MOC_LITERAL(6, 77, 8), // "fileName"
QT_MOC_LITERAL(7, 86, 10), // "endMonitor"
QT_MOC_LITERAL(8, 97, 5) // "proid"

    },
    "Post::RealTimeWindowBase\0closeWindow\0"
    "\0Post::RealTimeWindowBase*\0w\0updatePlot\0"
    "fileName\0endMonitor\0proid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Post__RealTimeWindowBase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   32,    2, 0x09 /* Protected */,
       7,    1,   35,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void Post::RealTimeWindowBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RealTimeWindowBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeWindow((*reinterpret_cast< Post::RealTimeWindowBase*(*)>(_a[1]))); break;
        case 1: _t->updatePlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->endMonitor((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Post::RealTimeWindowBase* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RealTimeWindowBase::*)(Post::RealTimeWindowBase * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RealTimeWindowBase::closeWindow)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Post::RealTimeWindowBase::staticMetaObject = { {
    QMetaObject::SuperData::link<ModuleBase::GraphWindowBase::staticMetaObject>(),
    qt_meta_stringdata_Post__RealTimeWindowBase.data,
    qt_meta_data_Post__RealTimeWindowBase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Post::RealTimeWindowBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Post::RealTimeWindowBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Post__RealTimeWindowBase.stringdata0))
        return static_cast<void*>(this);
    return ModuleBase::GraphWindowBase::qt_metacast(_clname);
}

int Post::RealTimeWindowBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModuleBase::GraphWindowBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Post::RealTimeWindowBase::closeWindow(Post::RealTimeWindowBase * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
