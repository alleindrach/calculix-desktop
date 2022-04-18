/****************************************************************************
** Meta object code from reading C++ file 'signalHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../signalHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'signalHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GUI__SignalHandler_t {
    QByteArrayData data[97];
    char stringdata0[1330];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUI__SignalHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUI__SignalHandler_t qt_meta_stringdata_GUI__SignalHandler = {
    {
QT_MOC_LITERAL(0, 0, 18), // "GUI::SignalHandler"
QT_MOC_LITERAL(1, 19, 15), // "importMeshPySig"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 15), // "exportMeshPySig"
QT_MOC_LITERAL(4, 52, 22), // "open3DGraphWindowPySig"
QT_MOC_LITERAL(5, 75, 21), // "open2DPlotWindowPySig"
QT_MOC_LITERAL(6, 97, 18), // "openProjectFileSig"
QT_MOC_LITERAL(7, 116, 8), // "fileName"
QT_MOC_LITERAL(8, 125, 20), // "saveToProjectFileSig"
QT_MOC_LITERAL(9, 146, 15), // "solveProjectSig"
QT_MOC_LITERAL(10, 162, 12), // "projectIndex"
QT_MOC_LITERAL(11, 175, 11), // "solverIndex"
QT_MOC_LITERAL(12, 187, 23), // "projectFileProcessedSig"
QT_MOC_LITERAL(13, 211, 4), // "file"
QT_MOC_LITERAL(14, 216, 7), // "success"
QT_MOC_LITERAL(15, 224, 6), // "isread"
QT_MOC_LITERAL(16, 231, 14), // "importMeshSlot"
QT_MOC_LITERAL(17, 246, 6), // "suffix"
QT_MOC_LITERAL(18, 253, 7), // "modelId"
QT_MOC_LITERAL(19, 261, 14), // "exportMeshSlot"
QT_MOC_LITERAL(20, 276, 9), // "clearData"
QT_MOC_LITERAL(21, 286, 6), // "unlock"
QT_MOC_LITERAL(22, 293, 14), // "on_actionSolve"
QT_MOC_LITERAL(23, 308, 16), // "on_actionEnglish"
QT_MOC_LITERAL(24, 325, 16), // "on_actionChinese"
QT_MOC_LITERAL(25, 342, 15), // "on_actionRibbon"
QT_MOC_LITERAL(26, 358, 15), // "on_actionNormal"
QT_MOC_LITERAL(27, 374, 20), // "handleTreeMouseEvent"
QT_MOC_LITERAL(28, 395, 9), // "eventtype"
QT_MOC_LITERAL(29, 405, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(30, 422, 4), // "item"
QT_MOC_LITERAL(31, 427, 5), // "proID"
QT_MOC_LITERAL(32, 433, 14), // "solveProjectPy"
QT_MOC_LITERAL(33, 448, 12), // "solveProject"
QT_MOC_LITERAL(34, 461, 19), // "generateSurfaceMesh"
QT_MOC_LITERAL(35, 481, 17), // "generateSolidMesh"
QT_MOC_LITERAL(36, 499, 17), // "generateFluidMesh"
QT_MOC_LITERAL(37, 517, 7), // "genMesh"
QT_MOC_LITERAL(38, 525, 19), // "appendGeneratedMesh"
QT_MOC_LITERAL(39, 545, 4), // "name"
QT_MOC_LITERAL(40, 550, 11), // "vtkDataSet*"
QT_MOC_LITERAL(41, 562, 7), // "dataset"
QT_MOC_LITERAL(42, 570, 19), // "updateActionsStates"
QT_MOC_LITERAL(43, 590, 16), // "open2DPlotWindow"
QT_MOC_LITERAL(44, 607, 18), // "open2DPlotWindowPy"
QT_MOC_LITERAL(45, 626, 17), // "open3DGraphWindow"
QT_MOC_LITERAL(46, 644, 19), // "open3DGraphWindowPy"
QT_MOC_LITERAL(47, 664, 15), // "closePostWindow"
QT_MOC_LITERAL(48, 680, 21), // "Post::PostWindowBase*"
QT_MOC_LITERAL(49, 702, 1), // "p"
QT_MOC_LITERAL(50, 704, 10), // "saveImange"
QT_MOC_LITERAL(51, 715, 15), // "openProjectFile"
QT_MOC_LITERAL(52, 731, 20), // "projectFileProcessed"
QT_MOC_LITERAL(53, 752, 8), // "filename"
QT_MOC_LITERAL(54, 761, 4), // "read"
QT_MOC_LITERAL(55, 766, 17), // "saveToProjectFile"
QT_MOC_LITERAL(56, 784, 12), // "meshChecking"
QT_MOC_LITERAL(57, 797, 16), // "showUserGuidence"
QT_MOC_LITERAL(58, 814, 5), // "start"
QT_MOC_LITERAL(59, 820, 4), // "undo"
QT_MOC_LITERAL(60, 825, 4), // "redo"
QT_MOC_LITERAL(61, 830, 9), // "createBox"
QT_MOC_LITERAL(62, 840, 14), // "createCylinder"
QT_MOC_LITERAL(63, 855, 12), // "CreateSphere"
QT_MOC_LITERAL(64, 868, 10), // "CreateCone"
QT_MOC_LITERAL(65, 879, 11), // "CreatePoint"
QT_MOC_LITERAL(66, 891, 10), // "CreateEdge"
QT_MOC_LITERAL(67, 902, 10), // "CreateFace"
QT_MOC_LITERAL(68, 913, 11), // "CreateFilet"
QT_MOC_LITERAL(69, 925, 20), // "CreateVariableFillet"
QT_MOC_LITERAL(70, 946, 13), // "CreateChamfer"
QT_MOC_LITERAL(71, 960, 13), // "CreateBoolCut"
QT_MOC_LITERAL(72, 974, 15), // "CreateBoolFause"
QT_MOC_LITERAL(73, 990, 16), // "CreateBoolCommon"
QT_MOC_LITERAL(74, 1007, 13), // "MirrorFeature"
QT_MOC_LITERAL(75, 1021, 15), // "CreateExtrusion"
QT_MOC_LITERAL(76, 1037, 11), // "MoveFeature"
QT_MOC_LITERAL(77, 1049, 13), // "RotateFeature"
QT_MOC_LITERAL(78, 1063, 11), // "CreateRevol"
QT_MOC_LITERAL(79, 1075, 10), // "CreateLoft"
QT_MOC_LITERAL(80, 1086, 11), // "CreateSweep"
QT_MOC_LITERAL(81, 1098, 16), // "CreateDatumplane"
QT_MOC_LITERAL(82, 1115, 16), // "DrawGraphicsLine"
QT_MOC_LITERAL(83, 1132, 21), // "DrawGraphicsRectangle"
QT_MOC_LITERAL(84, 1154, 18), // "DrawGraphicsCircle"
QT_MOC_LITERAL(85, 1173, 15), // "DrawGraphicsArc"
QT_MOC_LITERAL(86, 1189, 20), // "DrawGraphicsPolyline"
QT_MOC_LITERAL(87, 1210, 15), // "DrawGraphSpline"
QT_MOC_LITERAL(88, 1226, 10), // "showDialog"
QT_MOC_LITERAL(89, 1237, 8), // "QDialog*"
QT_MOC_LITERAL(90, 1246, 1), // "d"
QT_MOC_LITERAL(91, 1248, 10), // "MakeMatrix"
QT_MOC_LITERAL(92, 1259, 15), // "MeasureDistance"
QT_MOC_LITERAL(93, 1275, 11), // "GeoSplitter"
QT_MOC_LITERAL(94, 1287, 12), // "MakeFillHole"
QT_MOC_LITERAL(95, 1300, 17), // "MakeRemoveSurface"
QT_MOC_LITERAL(96, 1318, 11) // "MakeFillGap"

    },
    "GUI::SignalHandler\0importMeshPySig\0\0"
    "exportMeshPySig\0open3DGraphWindowPySig\0"
    "open2DPlotWindowPySig\0openProjectFileSig\0"
    "fileName\0saveToProjectFileSig\0"
    "solveProjectSig\0projectIndex\0solverIndex\0"
    "projectFileProcessedSig\0file\0success\0"
    "isread\0importMeshSlot\0suffix\0modelId\0"
    "exportMeshSlot\0clearData\0unlock\0"
    "on_actionSolve\0on_actionEnglish\0"
    "on_actionChinese\0on_actionRibbon\0"
    "on_actionNormal\0handleTreeMouseEvent\0"
    "eventtype\0QTreeWidgetItem*\0item\0proID\0"
    "solveProjectPy\0solveProject\0"
    "generateSurfaceMesh\0generateSolidMesh\0"
    "generateFluidMesh\0genMesh\0appendGeneratedMesh\0"
    "name\0vtkDataSet*\0dataset\0updateActionsStates\0"
    "open2DPlotWindow\0open2DPlotWindowPy\0"
    "open3DGraphWindow\0open3DGraphWindowPy\0"
    "closePostWindow\0Post::PostWindowBase*\0"
    "p\0saveImange\0openProjectFile\0"
    "projectFileProcessed\0filename\0read\0"
    "saveToProjectFile\0meshChecking\0"
    "showUserGuidence\0start\0undo\0redo\0"
    "createBox\0createCylinder\0CreateSphere\0"
    "CreateCone\0CreatePoint\0CreateEdge\0"
    "CreateFace\0CreateFilet\0CreateVariableFillet\0"
    "CreateChamfer\0CreateBoolCut\0CreateBoolFause\0"
    "CreateBoolCommon\0MirrorFeature\0"
    "CreateExtrusion\0MoveFeature\0RotateFeature\0"
    "CreateRevol\0CreateLoft\0CreateSweep\0"
    "CreateDatumplane\0DrawGraphicsLine\0"
    "DrawGraphicsRectangle\0DrawGraphicsCircle\0"
    "DrawGraphicsArc\0DrawGraphicsPolyline\0"
    "DrawGraphSpline\0showDialog\0QDialog*\0"
    "d\0MakeMatrix\0MeasureDistance\0GeoSplitter\0"
    "MakeFillHole\0MakeRemoveSurface\0"
    "MakeFillGap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI__SignalHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      74,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  384,    2, 0x06 /* Public */,
       3,    3,  391,    2, 0x06 /* Public */,
       4,    0,  398,    2, 0x06 /* Public */,
       5,    0,  399,    2, 0x06 /* Public */,
       6,    1,  400,    2, 0x06 /* Public */,
       8,    1,  403,    2, 0x06 /* Public */,
       9,    2,  406,    2, 0x06 /* Public */,
      12,    3,  411,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    3,  418,    2, 0x0a /* Public */,
      19,    3,  425,    2, 0x0a /* Public */,
      20,    1,  432,    2, 0x0a /* Public */,
      20,    0,  435,    2, 0x2a /* Public | MethodCloned */,
      22,    0,  436,    2, 0x0a /* Public */,
      23,    0,  437,    2, 0x0a /* Public */,
      24,    0,  438,    2, 0x0a /* Public */,
      25,    0,  439,    2, 0x0a /* Public */,
      26,    0,  440,    2, 0x0a /* Public */,
      27,    3,  441,    2, 0x0a /* Public */,
      32,    2,  448,    2, 0x0a /* Public */,
      33,    2,  453,    2, 0x0a /* Public */,
      34,    0,  458,    2, 0x0a /* Public */,
      35,    0,  459,    2, 0x0a /* Public */,
      36,    0,  460,    2, 0x0a /* Public */,
      37,    0,  461,    2, 0x0a /* Public */,
      38,    2,  462,    2, 0x0a /* Public */,
      42,    0,  467,    2, 0x0a /* Public */,
      43,    0,  468,    2, 0x0a /* Public */,
      44,    0,  469,    2, 0x0a /* Public */,
      45,    0,  470,    2, 0x0a /* Public */,
      46,    0,  471,    2, 0x0a /* Public */,
      47,    1,  472,    2, 0x0a /* Public */,
      50,    0,  475,    2, 0x0a /* Public */,
      51,    1,  476,    2, 0x0a /* Public */,
      52,    3,  479,    2, 0x0a /* Public */,
      55,    1,  486,    2, 0x0a /* Public */,
      56,    0,  489,    2, 0x0a /* Public */,
      57,    1,  490,    2, 0x0a /* Public */,
      57,    0,  493,    2, 0x2a /* Public | MethodCloned */,
      59,    0,  494,    2, 0x0a /* Public */,
      60,    0,  495,    2, 0x0a /* Public */,
      61,    0,  496,    2, 0x0a /* Public */,
      62,    0,  497,    2, 0x0a /* Public */,
      63,    0,  498,    2, 0x0a /* Public */,
      64,    0,  499,    2, 0x0a /* Public */,
      65,    0,  500,    2, 0x0a /* Public */,
      66,    0,  501,    2, 0x0a /* Public */,
      67,    0,  502,    2, 0x0a /* Public */,
      68,    0,  503,    2, 0x0a /* Public */,
      69,    0,  504,    2, 0x0a /* Public */,
      70,    0,  505,    2, 0x0a /* Public */,
      71,    0,  506,    2, 0x0a /* Public */,
      72,    0,  507,    2, 0x0a /* Public */,
      73,    0,  508,    2, 0x0a /* Public */,
      74,    0,  509,    2, 0x0a /* Public */,
      75,    0,  510,    2, 0x0a /* Public */,
      76,    0,  511,    2, 0x0a /* Public */,
      77,    0,  512,    2, 0x0a /* Public */,
      78,    0,  513,    2, 0x0a /* Public */,
      79,    0,  514,    2, 0x0a /* Public */,
      80,    0,  515,    2, 0x0a /* Public */,
      81,    0,  516,    2, 0x0a /* Public */,
      82,    0,  517,    2, 0x0a /* Public */,
      83,    0,  518,    2, 0x0a /* Public */,
      84,    0,  519,    2, 0x0a /* Public */,
      85,    0,  520,    2, 0x0a /* Public */,
      86,    0,  521,    2, 0x0a /* Public */,
      87,    0,  522,    2, 0x0a /* Public */,
      88,    1,  523,    2, 0x0a /* Public */,
      91,    0,  526,    2, 0x0a /* Public */,
      92,    0,  527,    2, 0x0a /* Public */,
      93,    0,  528,    2, 0x0a /* Public */,
      94,    0,  529,    2, 0x0a /* Public */,
      95,    0,  530,    2, 0x0a /* Public */,
      96,    0,  531,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,   13,   14,   15,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int,    7,   17,   18,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int,    7,   17,   18,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 29, QMetaType::Int,   28,   30,   31,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 40,   39,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 48,   49,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,   53,   14,   54,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   58,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 89,   90,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GUI::SignalHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SignalHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->importMeshPySig((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->exportMeshPySig((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->open3DGraphWindowPySig(); break;
        case 3: _t->open2DPlotWindowPySig(); break;
        case 4: { bool _r = _t->openProjectFileSig((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->saveToProjectFileSig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->solveProjectSig((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->projectFileProcessedSig((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 8: { bool _r = _t->importMeshSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->exportMeshSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->clearData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->clearData(); break;
        case 12: _t->on_actionSolve(); break;
        case 13: _t->on_actionEnglish(); break;
        case 14: _t->on_actionChinese(); break;
        case 15: _t->on_actionRibbon(); break;
        case 16: _t->on_actionNormal(); break;
        case 17: _t->handleTreeMouseEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 18: _t->solveProjectPy((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->solveProject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: _t->generateSurfaceMesh(); break;
        case 21: _t->generateSolidMesh(); break;
        case 22: _t->generateFluidMesh(); break;
        case 23: _t->genMesh(); break;
        case 24: _t->appendGeneratedMesh((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< vtkDataSet*(*)>(_a[2]))); break;
        case 25: _t->updateActionsStates(); break;
        case 26: _t->open2DPlotWindow(); break;
        case 27: _t->open2DPlotWindowPy(); break;
        case 28: _t->open3DGraphWindow(); break;
        case 29: _t->open3DGraphWindowPy(); break;
        case 30: _t->closePostWindow((*reinterpret_cast< Post::PostWindowBase*(*)>(_a[1]))); break;
        case 31: _t->saveImange(); break;
        case 32: { bool _r = _t->openProjectFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 33: _t->projectFileProcessed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 34: _t->saveToProjectFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: _t->meshChecking(); break;
        case 36: _t->showUserGuidence((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->showUserGuidence(); break;
        case 38: _t->undo(); break;
        case 39: _t->redo(); break;
        case 40: _t->createBox(); break;
        case 41: _t->createCylinder(); break;
        case 42: _t->CreateSphere(); break;
        case 43: _t->CreateCone(); break;
        case 44: _t->CreatePoint(); break;
        case 45: _t->CreateEdge(); break;
        case 46: _t->CreateFace(); break;
        case 47: _t->CreateFilet(); break;
        case 48: _t->CreateVariableFillet(); break;
        case 49: _t->CreateChamfer(); break;
        case 50: _t->CreateBoolCut(); break;
        case 51: _t->CreateBoolFause(); break;
        case 52: _t->CreateBoolCommon(); break;
        case 53: _t->MirrorFeature(); break;
        case 54: _t->CreateExtrusion(); break;
        case 55: _t->MoveFeature(); break;
        case 56: _t->RotateFeature(); break;
        case 57: _t->CreateRevol(); break;
        case 58: _t->CreateLoft(); break;
        case 59: _t->CreateSweep(); break;
        case 60: _t->CreateDatumplane(); break;
        case 61: _t->DrawGraphicsLine(); break;
        case 62: _t->DrawGraphicsRectangle(); break;
        case 63: _t->DrawGraphicsCircle(); break;
        case 64: _t->DrawGraphicsArc(); break;
        case 65: _t->DrawGraphicsPolyline(); break;
        case 66: _t->DrawGraphSpline(); break;
        case 67: _t->showDialog((*reinterpret_cast< QDialog*(*)>(_a[1]))); break;
        case 68: _t->MakeMatrix(); break;
        case 69: _t->MeasureDistance(); break;
        case 70: _t->GeoSplitter(); break;
        case 71: _t->MakeFillHole(); break;
        case 72: _t->MakeRemoveSurface(); break;
        case 73: _t->MakeFillGap(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SignalHandler::*)(QString , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SignalHandler::importMeshPySig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SignalHandler::*)(QString , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SignalHandler::exportMeshPySig)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SignalHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SignalHandler::open3DGraphWindowPySig)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SignalHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SignalHandler::open2DPlotWindowPySig)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = bool (SignalHandler::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SignalHandler::openProjectFileSig)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SignalHandler::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SignalHandler::saveToProjectFileSig)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SignalHandler::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SignalHandler::solveProjectSig)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SignalHandler::*)(QString , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SignalHandler::projectFileProcessedSig)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GUI::SignalHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GUI__SignalHandler.data,
    qt_meta_data_GUI__SignalHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GUI::SignalHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI::SignalHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GUI__SignalHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GUI::SignalHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 74)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 74;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 74)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 74;
    }
    return _id;
}

// SIGNAL 0
void GUI::SignalHandler::importMeshPySig(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GUI::SignalHandler::exportMeshPySig(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GUI::SignalHandler::open3DGraphWindowPySig()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GUI::SignalHandler::open2DPlotWindowPySig()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
bool GUI::SignalHandler::openProjectFileSig(QString _t1)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
    return _t0;
}

// SIGNAL 5
void GUI::SignalHandler::saveToProjectFileSig(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GUI::SignalHandler::solveProjectSig(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GUI::SignalHandler::projectFileProcessedSig(QString _t1, bool _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
