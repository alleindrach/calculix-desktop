/****************************************************************************
** Meta object code from reading C++ file 'geometryViewProvider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../geometryViewProvider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'geometryViewProvider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWidget__GeometryViewProvider_t {
    QByteArrayData data[32];
    char stringdata0[396];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWidget__GeometryViewProvider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWidget__GeometryViewProvider_t qt_meta_stringdata_MainWidget__GeometryViewProvider = {
    {
QT_MOC_LITERAL(0, 0, 32), // "MainWidget::GeometryViewProvider"
QT_MOC_LITERAL(1, 33, 16), // "geoShapeSelected"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 22), // "Geometry::GeometrySet*"
QT_MOC_LITERAL(4, 74, 5), // "shape"
QT_MOC_LITERAL(5, 80, 5), // "index"
QT_MOC_LITERAL(6, 86, 10), // "showGeoSet"
QT_MOC_LITERAL(7, 97, 3), // "set"
QT_MOC_LITERAL(8, 101, 6), // "render"
QT_MOC_LITERAL(9, 108, 9), // "showDatum"
QT_MOC_LITERAL(10, 118, 24), // "Geometry::GeometryDatum*"
QT_MOC_LITERAL(11, 143, 4), // "datm"
QT_MOC_LITERAL(12, 148, 12), // "removeActors"
QT_MOC_LITERAL(13, 161, 18), // "setGeometryDisplay"
QT_MOC_LITERAL(14, 180, 1), // "v"
QT_MOC_LITERAL(15, 182, 1), // "c"
QT_MOC_LITERAL(16, 184, 1), // "f"
QT_MOC_LITERAL(17, 186, 16), // "setGeoSelectMode"
QT_MOC_LITERAL(18, 203, 20), // "highLightGeometrySet"
QT_MOC_LITERAL(19, 224, 1), // "s"
QT_MOC_LITERAL(20, 226, 2), // "on"
QT_MOC_LITERAL(21, 229, 21), // "highLightGeometryFace"
QT_MOC_LITERAL(22, 251, 2), // "id"
QT_MOC_LITERAL(23, 254, 21), // "highLightGeometryEdge"
QT_MOC_LITERAL(24, 276, 22), // "highLightGeometryPoint"
QT_MOC_LITERAL(25, 299, 22), // "highLightGeometrySolid"
QT_MOC_LITERAL(26, 322, 14), // "selectGeometry"
QT_MOC_LITERAL(27, 337, 9), // "ctrlpress"
QT_MOC_LITERAL(28, 347, 17), // "preSelectGeometry"
QT_MOC_LITERAL(29, 365, 9), // "vtkActor*"
QT_MOC_LITERAL(30, 375, 2), // "ac"
QT_MOC_LITERAL(31, 378, 17) // "clearAllHighLight"

    },
    "MainWidget::GeometryViewProvider\0"
    "geoShapeSelected\0\0Geometry::GeometrySet*\0"
    "shape\0index\0showGeoSet\0set\0render\0"
    "showDatum\0Geometry::GeometryDatum*\0"
    "datm\0removeActors\0setGeometryDisplay\0"
    "v\0c\0f\0setGeoSelectMode\0highLightGeometrySet\0"
    "s\0on\0highLightGeometryFace\0id\0"
    "highLightGeometryEdge\0highLightGeometryPoint\0"
    "highLightGeometrySolid\0selectGeometry\0"
    "ctrlpress\0preSelectGeometry\0vtkActor*\0"
    "ac\0clearAllHighLight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWidget__GeometryViewProvider[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   94,    2, 0x0a /* Public */,
       6,    1,   99,    2, 0x2a /* Public | MethodCloned */,
       9,    1,  102,    2, 0x0a /* Public */,
      12,    1,  105,    2, 0x0a /* Public */,
      13,    3,  108,    2, 0x0a /* Public */,
      17,    1,  115,    2, 0x0a /* Public */,
      18,    2,  118,    2, 0x08 /* Private */,
      21,    3,  123,    2, 0x08 /* Private */,
      23,    3,  130,    2, 0x08 /* Private */,
      24,    3,  137,    2, 0x08 /* Private */,
      25,    3,  144,    2, 0x08 /* Private */,
      26,    1,  151,    2, 0x08 /* Private */,
      28,    2,  154,    2, 0x08 /* Private */,
      31,    0,  159,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    7,    8,
    QMetaType::Void, 0x80000000 | 3,    7,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 3,    7,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   16,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,   19,   20,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Bool,   19,   22,   20,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Bool,   19,   22,   20,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Bool,   19,   22,   20,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Bool,   19,   22,   20,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, 0x80000000 | 29, QMetaType::Int,   30,    5,
    QMetaType::Void,

       0        // eod
};

void MainWidget::GeometryViewProvider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeometryViewProvider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->geoShapeSelected((*reinterpret_cast< Geometry::GeometrySet*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->showGeoSet((*reinterpret_cast< Geometry::GeometrySet*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->showGeoSet((*reinterpret_cast< Geometry::GeometrySet*(*)>(_a[1]))); break;
        case 3: _t->showDatum((*reinterpret_cast< Geometry::GeometryDatum*(*)>(_a[1]))); break;
        case 4: _t->removeActors((*reinterpret_cast< Geometry::GeometrySet*(*)>(_a[1]))); break;
        case 5: _t->setGeometryDisplay((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->setGeoSelectMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->highLightGeometrySet((*reinterpret_cast< Geometry::GeometrySet*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->highLightGeometryFace((*reinterpret_cast< Geometry::GeometrySet*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 9: _t->highLightGeometryEdge((*reinterpret_cast< Geometry::GeometrySet*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 10: _t->highLightGeometryPoint((*reinterpret_cast< Geometry::GeometrySet*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 11: _t->highLightGeometrySolid((*reinterpret_cast< Geometry::GeometrySet*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 12: _t->selectGeometry((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->preSelectGeometry((*reinterpret_cast< vtkActor*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->clearAllHighLight(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GeometryViewProvider::*)(Geometry::GeometrySet * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GeometryViewProvider::geoShapeSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWidget::GeometryViewProvider::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MainWidget__GeometryViewProvider.data,
    qt_meta_data_MainWidget__GeometryViewProvider,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWidget::GeometryViewProvider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWidget::GeometryViewProvider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWidget__GeometryViewProvider.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MainWidget::GeometryViewProvider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MainWidget::GeometryViewProvider::geoShapeSelected(Geometry::GeometrySet * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
