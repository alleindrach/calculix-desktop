/****************************************************************************
** Meta object code from reading C++ file 'EditorCurveModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../EditorCurveModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditorCurveModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FastCAEDesigner__EditorCurveModel_t {
    QByteArrayData data[11];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FastCAEDesigner__EditorCurveModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FastCAEDesigner__EditorCurveModel_t qt_meta_stringdata_FastCAEDesigner__EditorCurveModel = {
    {
QT_MOC_LITERAL(0, 0, 33), // "FastCAEDesigner::EditorCurveM..."
QT_MOC_LITERAL(1, 34, 9), // "deleteRow"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 11), // "editRowInfo"
QT_MOC_LITERAL(4, 57, 15), // "OnOkPBtnClicked"
QT_MOC_LITERAL(5, 73, 19), // "OnInsertPBtnClicked"
QT_MOC_LITERAL(6, 93, 12), // "deleteRow_3D"
QT_MOC_LITERAL(7, 106, 14), // "editRowInfo_3D"
QT_MOC_LITERAL(8, 121, 18), // "OnOkPBtnClicked_3D"
QT_MOC_LITERAL(9, 140, 22), // "OnInsertPBtnClicked_3D"
QT_MOC_LITERAL(10, 163, 9) // "OnTimeout"

    },
    "FastCAEDesigner::EditorCurveModel\0"
    "deleteRow\0\0editRowInfo\0OnOkPBtnClicked\0"
    "OnInsertPBtnClicked\0deleteRow_3D\0"
    "editRowInfo_3D\0OnOkPBtnClicked_3D\0"
    "OnInsertPBtnClicked_3D\0OnTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FastCAEDesigner__EditorCurveModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       3,    1,   62,    2, 0x08 /* Private */,
       4,    0,   65,    2, 0x08 /* Private */,
       5,    0,   66,    2, 0x08 /* Private */,
       6,    1,   67,    2, 0x08 /* Private */,
       7,    1,   70,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FastCAEDesigner::EditorCurveModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditorCurveModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->editRowInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OnOkPBtnClicked(); break;
        case 3: _t->OnInsertPBtnClicked(); break;
        case 4: _t->deleteRow_3D((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->editRowInfo_3D((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->OnOkPBtnClicked_3D(); break;
        case 7: _t->OnInsertPBtnClicked_3D(); break;
        case 8: _t->OnTimeout(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FastCAEDesigner::EditorCurveModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_FastCAEDesigner__EditorCurveModel.data,
    qt_meta_data_FastCAEDesigner__EditorCurveModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FastCAEDesigner::EditorCurveModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FastCAEDesigner::EditorCurveModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FastCAEDesigner__EditorCurveModel.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int FastCAEDesigner::EditorCurveModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
