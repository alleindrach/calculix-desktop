/****************************************************************************
** Meta object code from reading C++ file 'vtkAniThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../vtkAniThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vtkAniThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_vtkAniThread_t {
    QByteArrayData data[8];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vtkAniThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vtkAniThread_t qt_meta_stringdata_vtkAniThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "vtkAniThread"
QT_MOC_LITERAL(1, 13, 20), // "sig_finish_aniThread"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 15), // "sig_refreshView"
QT_MOC_LITERAL(4, 51, 22), // "QList<PipelineObject*>"
QT_MOC_LITERAL(5, 74, 18), // "sig_refreshViewAni"
QT_MOC_LITERAL(6, 93, 18), // "sig_offPlaneWidget"
QT_MOC_LITERAL(7, 112, 15) // "PipelineObject*"

    },
    "vtkAniThread\0sig_finish_aniThread\0\0"
    "sig_refreshView\0QList<PipelineObject*>\0"
    "sig_refreshViewAni\0sig_offPlaneWidget\0"
    "PipelineObject*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vtkAniThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,
       6,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void vtkAniThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<vtkAniThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_finish_aniThread((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sig_refreshView((*reinterpret_cast< QList<PipelineObject*>(*)>(_a[1]))); break;
        case 2: _t->sig_refreshViewAni((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sig_offPlaneWidget((*reinterpret_cast< PipelineObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<PipelineObject*> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PipelineObject* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (vtkAniThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&vtkAniThread::sig_finish_aniThread)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (vtkAniThread::*)(QList<PipelineObject*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&vtkAniThread::sig_refreshView)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (vtkAniThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&vtkAniThread::sig_refreshViewAni)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (vtkAniThread::*)(PipelineObject * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&vtkAniThread::sig_offPlaneWidget)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject vtkAniThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_vtkAniThread.data,
    qt_meta_data_vtkAniThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *vtkAniThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vtkAniThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_vtkAniThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int vtkAniThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void vtkAniThread::sig_finish_aniThread(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vtkAniThread::sig_refreshView(QList<PipelineObject*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void vtkAniThread::sig_refreshViewAni(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void vtkAniThread::sig_offPlaneWidget(PipelineObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
