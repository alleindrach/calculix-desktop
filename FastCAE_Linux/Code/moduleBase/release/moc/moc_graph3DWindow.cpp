/****************************************************************************
** Meta object code from reading C++ file 'graph3DWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../graph3DWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graph3DWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModuleBase__Graph3DWindow_t {
    QByteArrayData data[25];
    char stringdata0[302];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModuleBase__Graph3DWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModuleBase__Graph3DWindow_t qt_meta_stringdata_ModuleBase__Graph3DWindow = {
    {
QT_MOC_LITERAL(0, 0, 25), // "ModuleBase::Graph3DWindow"
QT_MOC_LITERAL(1, 26, 8), // "keyEvent"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "type"
QT_MOC_LITERAL(4, 41, 10), // "QKeyEvent*"
QT_MOC_LITERAL(5, 52, 1), // "e"
QT_MOC_LITERAL(6, 54, 14), // "selectGeometry"
QT_MOC_LITERAL(7, 69, 9), // "ctrlpress"
QT_MOC_LITERAL(8, 79, 17), // "preSelectGeometry"
QT_MOC_LITERAL(9, 97, 9), // "vtkActor*"
QT_MOC_LITERAL(10, 107, 5), // "actor"
QT_MOC_LITERAL(11, 113, 5), // "index"
QT_MOC_LITERAL(12, 119, 11), // "reRenderSig"
QT_MOC_LITERAL(13, 131, 17), // "clearAllHighLight"
QT_MOC_LITERAL(14, 149, 16), // "rightDownMenuSig"
QT_MOC_LITERAL(15, 166, 11), // "highLighSet"
QT_MOC_LITERAL(16, 178, 28), // "QMultiHash<vtkDataSet*,int>*"
QT_MOC_LITERAL(17, 207, 5), // "items"
QT_MOC_LITERAL(18, 213, 26), // "highLightActorDispalyPoint"
QT_MOC_LITERAL(19, 240, 2), // "on"
QT_MOC_LITERAL(20, 243, 8), // "reRender"
QT_MOC_LITERAL(21, 252, 13), // "setSelectType"
QT_MOC_LITERAL(22, 266, 5), // "model"
QT_MOC_LITERAL(23, 272, 14), // "enableKeyBoard"
QT_MOC_LITERAL(24, 287, 14) // "mouseWheelMove"

    },
    "ModuleBase::Graph3DWindow\0keyEvent\0\0"
    "type\0QKeyEvent*\0e\0selectGeometry\0"
    "ctrlpress\0preSelectGeometry\0vtkActor*\0"
    "actor\0index\0reRenderSig\0clearAllHighLight\0"
    "rightDownMenuSig\0highLighSet\0"
    "QMultiHash<vtkDataSet*,int>*\0items\0"
    "highLightActorDispalyPoint\0on\0reRender\0"
    "setSelectType\0model\0enableKeyBoard\0"
    "mouseWheelMove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModuleBase__Graph3DWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       6,    1,   79,    2, 0x06 /* Public */,
       8,    2,   82,    2, 0x06 /* Public */,
      12,    0,   87,    2, 0x06 /* Public */,
      13,    0,   88,    2, 0x06 /* Public */,
      14,    0,   89,    2, 0x06 /* Public */,
      15,    1,   90,    2, 0x06 /* Public */,
      18,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,   96,    2, 0x0a /* Public */,
      21,    1,   97,    2, 0x09 /* Protected */,
      23,    1,  100,    2, 0x09 /* Protected */,
      24,    0,  103,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::Bool,   19,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,

       0        // eod
};

void ModuleBase::Graph3DWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Graph3DWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->keyEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QKeyEvent*(*)>(_a[2]))); break;
        case 1: _t->selectGeometry((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->preSelectGeometry((*reinterpret_cast< vtkActor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->reRenderSig(); break;
        case 4: _t->clearAllHighLight(); break;
        case 5: _t->rightDownMenuSig(); break;
        case 6: _t->highLighSet((*reinterpret_cast< QMultiHash<vtkDataSet*,int>*(*)>(_a[1]))); break;
        case 7: _t->highLightActorDispalyPoint((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->reRender(); break;
        case 9: _t->setSelectType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->enableKeyBoard((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->mouseWheelMove(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Graph3DWindow::*)(int , QKeyEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Graph3DWindow::keyEvent)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Graph3DWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Graph3DWindow::selectGeometry)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Graph3DWindow::*)(vtkActor * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Graph3DWindow::preSelectGeometry)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Graph3DWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Graph3DWindow::reRenderSig)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Graph3DWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Graph3DWindow::clearAllHighLight)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Graph3DWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Graph3DWindow::rightDownMenuSig)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Graph3DWindow::*)(QMultiHash<vtkDataSet*,int> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Graph3DWindow::highLighSet)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Graph3DWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Graph3DWindow::highLightActorDispalyPoint)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ModuleBase::Graph3DWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphWindowBase::staticMetaObject>(),
    qt_meta_stringdata_ModuleBase__Graph3DWindow.data,
    qt_meta_data_ModuleBase__Graph3DWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModuleBase::Graph3DWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModuleBase::Graph3DWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModuleBase__Graph3DWindow.stringdata0))
        return static_cast<void*>(this);
    return GraphWindowBase::qt_metacast(_clname);
}

int ModuleBase::Graph3DWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphWindowBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ModuleBase::Graph3DWindow::keyEvent(int _t1, QKeyEvent * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModuleBase::Graph3DWindow::selectGeometry(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ModuleBase::Graph3DWindow::preSelectGeometry(vtkActor * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ModuleBase::Graph3DWindow::reRenderSig()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ModuleBase::Graph3DWindow::clearAllHighLight()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ModuleBase::Graph3DWindow::rightDownMenuSig()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ModuleBase::Graph3DWindow::highLighSet(QMultiHash<vtkDataSet*,int> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ModuleBase::Graph3DWindow::highLightActorDispalyPoint(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
