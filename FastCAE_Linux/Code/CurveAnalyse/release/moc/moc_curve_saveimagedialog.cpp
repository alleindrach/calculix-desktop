/****************************************************************************
** Meta object code from reading C++ file 'curve_saveimagedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../curve_saveimagedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'curve_saveimagedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_curve_saveImageDialog_t {
    QByteArrayData data[8];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_curve_saveImageDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_curve_saveImageDialog_t qt_meta_stringdata_curve_saveImageDialog = {
    {
QT_MOC_LITERAL(0, 0, 21), // "curve_saveImageDialog"
QT_MOC_LITERAL(1, 22, 31), // "on_imagePath_pushButton_clicked"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 26), // "on_save_pushButton_clicked"
QT_MOC_LITERAL(4, 82, 27), // "on_close_pushButton_clicked"
QT_MOC_LITERAL(5, 110, 27), // "on_wid_lineEdit_textChanged"
QT_MOC_LITERAL(6, 138, 4), // "arg1"
QT_MOC_LITERAL(7, 143, 27) // "on_hei_lineEdit_textChanged"

    },
    "curve_saveImageDialog\0"
    "on_imagePath_pushButton_clicked\0\0"
    "on_save_pushButton_clicked\0"
    "on_close_pushButton_clicked\0"
    "on_wid_lineEdit_textChanged\0arg1\0"
    "on_hei_lineEdit_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_curve_saveImageDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void curve_saveImageDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<curve_saveImageDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_imagePath_pushButton_clicked(); break;
        case 1: _t->on_save_pushButton_clicked(); break;
        case 2: _t->on_close_pushButton_clicked(); break;
        case 3: _t->on_wid_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_hei_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject curve_saveImageDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_curve_saveImageDialog.data,
    qt_meta_data_curve_saveImageDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *curve_saveImageDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *curve_saveImageDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_curve_saveImageDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int curve_saveImageDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
