/********************************************************************************
** Form generated from reading UI file 'ParaExportMeshSetup.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAEXPORTMESHSETUP_H
#define UI_PARAEXPORTMESHSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ParaExportMeshSetup
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *chk_selectall;
    QSpacerItem *horizontalSpacer_13;
    QCheckBox *BinaryExport;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chk_nastran;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_22;
    QCheckBox *chk_flunet_2;
    QSpacerItem *horizontalSpacer_23;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *chk_gambit;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *chk_flunet;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *chk_tecplot;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QCheckBox *chk_vtk;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_20;
    QCheckBox *chk_inp;
    QSpacerItem *horizontalSpacer_21;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_16;
    QCheckBox *chk_cntm;
    QSpacerItem *horizontalSpacer_17;
    QGridLayout *gridLayout;
    QCheckBox *chk_su2;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_15;
    QGridLayout *gridLayout_2;
    QCheckBox *chk_key;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_18;
    QCheckBox *chk_pdb;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *btnOk_2;
    QSpacerItem *horizontalSpacer_24;
    QPushButton *btnCancel_2;

    void setupUi(QDialog *ParaExportMeshSetup)
    {
        if (ParaExportMeshSetup->objectName().isEmpty())
            ParaExportMeshSetup->setObjectName(QString::fromUtf8("ParaExportMeshSetup"));
        ParaExportMeshSetup->resize(361, 469);
        gridLayout_3 = new QGridLayout(ParaExportMeshSetup);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        chk_selectall = new QCheckBox(ParaExportMeshSetup);
        chk_selectall->setObjectName(QString::fromUtf8("chk_selectall"));

        horizontalLayout_8->addWidget(chk_selectall);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);

        BinaryExport = new QCheckBox(ParaExportMeshSetup);
        BinaryExport->setObjectName(QString::fromUtf8("BinaryExport"));

        horizontalLayout_8->addWidget(BinaryExport);


        gridLayout_3->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        chk_nastran = new QCheckBox(ParaExportMeshSetup);
        chk_nastran->setObjectName(QString::fromUtf8("chk_nastran"));
        chk_nastran->setEnabled(false);
        chk_nastran->setMinimumSize(QSize(110, 0));

        horizontalLayout->addWidget(chk_nastran);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_22);

        chk_flunet_2 = new QCheckBox(ParaExportMeshSetup);
        chk_flunet_2->setObjectName(QString::fromUtf8("chk_flunet_2"));
        chk_flunet_2->setEnabled(false);
        chk_flunet_2->setMinimumSize(QSize(110, 0));

        horizontalLayout_13->addWidget(chk_flunet_2);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_23);


        gridLayout_3->addLayout(horizontalLayout_13, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        chk_gambit = new QCheckBox(ParaExportMeshSetup);
        chk_gambit->setObjectName(QString::fromUtf8("chk_gambit"));
        chk_gambit->setEnabled(true);
        chk_gambit->setMinimumSize(QSize(110, 0));

        horizontalLayout_2->addWidget(chk_gambit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        gridLayout_3->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        chk_flunet = new QCheckBox(ParaExportMeshSetup);
        chk_flunet->setObjectName(QString::fromUtf8("chk_flunet"));
        chk_flunet->setEnabled(false);
        chk_flunet->setMinimumSize(QSize(110, 0));

        horizontalLayout_3->addWidget(chk_flunet);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        gridLayout_3->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        chk_tecplot = new QCheckBox(ParaExportMeshSetup);
        chk_tecplot->setObjectName(QString::fromUtf8("chk_tecplot"));
        chk_tecplot->setEnabled(false);
        chk_tecplot->setMinimumSize(QSize(110, 0));

        horizontalLayout_4->addWidget(chk_tecplot);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);

        gridLayout_3->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        chk_vtk = new QCheckBox(ParaExportMeshSetup);
        chk_vtk->setObjectName(QString::fromUtf8("chk_vtk"));
        chk_vtk->setMinimumSize(QSize(110, 0));

        horizontalLayout_5->addWidget(chk_vtk);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);

        gridLayout_3->addLayout(horizontalLayout_5, 6, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_20);

        chk_inp = new QCheckBox(ParaExportMeshSetup);
        chk_inp->setObjectName(QString::fromUtf8("chk_inp"));
        chk_inp->setMinimumSize(QSize(110, 0));

        horizontalLayout_9->addWidget(chk_inp);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_21);


        gridLayout_3->addLayout(horizontalLayout_9, 7, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_16);

        chk_cntm = new QCheckBox(ParaExportMeshSetup);
        chk_cntm->setObjectName(QString::fromUtf8("chk_cntm"));
        chk_cntm->setEnabled(false);
        chk_cntm->setMinimumSize(QSize(110, 0));

        horizontalLayout_6->addWidget(chk_cntm);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_17);


        gridLayout_3->addLayout(horizontalLayout_6, 8, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        chk_su2 = new QCheckBox(ParaExportMeshSetup);
        chk_su2->setObjectName(QString::fromUtf8("chk_su2"));
        chk_su2->setEnabled(false);
        chk_su2->setMinimumSize(QSize(110, 0));

        gridLayout->addWidget(chk_su2, 0, 1, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 0, 2, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_15, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 9, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        chk_key = new QCheckBox(ParaExportMeshSetup);
        chk_key->setObjectName(QString::fromUtf8("chk_key"));
        chk_key->setEnabled(false);
        chk_key->setMinimumSize(QSize(110, 0));

        gridLayout_2->addWidget(chk_key, 0, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_11, 0, 2, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_12, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 10, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_18);

        chk_pdb = new QCheckBox(ParaExportMeshSetup);
        chk_pdb->setObjectName(QString::fromUtf8("chk_pdb"));
        chk_pdb->setEnabled(false);
        chk_pdb->setMinimumSize(QSize(110, 0));

        horizontalLayout_7->addWidget(chk_pdb);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_19);


        gridLayout_3->addLayout(horizontalLayout_7, 11, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        btnOk_2 = new QPushButton(ParaExportMeshSetup);
        btnOk_2->setObjectName(QString::fromUtf8("btnOk_2"));

        horizontalLayout_14->addWidget(btnOk_2);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_24);

        btnCancel_2 = new QPushButton(ParaExportMeshSetup);
        btnCancel_2->setObjectName(QString::fromUtf8("btnCancel_2"));

        horizontalLayout_14->addWidget(btnCancel_2);


        gridLayout_3->addLayout(horizontalLayout_14, 12, 0, 1, 1);


        retranslateUi(ParaExportMeshSetup);

        QMetaObject::connectSlotsByName(ParaExportMeshSetup);
    } // setupUi

    void retranslateUi(QDialog *ParaExportMeshSetup)
    {
        ParaExportMeshSetup->setWindowTitle(QCoreApplication::translate("ParaExportMeshSetup", "Export mesh setup", nullptr));
        chk_selectall->setText(QCoreApplication::translate("ParaExportMeshSetup", "Select all", nullptr));
        BinaryExport->setText(QCoreApplication::translate("ParaExportMeshSetup", "Binary Export", nullptr));
        chk_nastran->setText(QCoreApplication::translate("ParaExportMeshSetup", "CGNS(*.cgns)", nullptr));
        chk_flunet_2->setText(QCoreApplication::translate("ParaExportMeshSetup", "Flunet(*.msh)", nullptr));
        chk_gambit->setText(QCoreApplication::translate("ParaExportMeshSetup", "Gambit(*.neu)", nullptr));
        chk_flunet->setText(QCoreApplication::translate("ParaExportMeshSetup", "STL(*.stl)", nullptr));
        chk_tecplot->setText(QCoreApplication::translate("ParaExportMeshSetup", "Tecplot(*.dat)", nullptr));
        chk_vtk->setText(QCoreApplication::translate("ParaExportMeshSetup", "VTK(*.vtk)", nullptr));
        chk_inp->setText(QCoreApplication::translate("ParaExportMeshSetup", "Abaqus(*.inp)", nullptr));
        chk_cntm->setText(QCoreApplication::translate("ParaExportMeshSetup", "CNTM(*.cntm)", nullptr));
        chk_su2->setText(QCoreApplication::translate("ParaExportMeshSetup", "SU2(*.su2)", nullptr));
        chk_key->setText(QCoreApplication::translate("ParaExportMeshSetup", "LS-DYNA(*.key)", nullptr));
        chk_pdb->setText(QCoreApplication::translate("ParaExportMeshSetup", "PDB(*.pdb)", nullptr));
        btnOk_2->setText(QCoreApplication::translate("ParaExportMeshSetup", "Ok", nullptr));
        btnCancel_2->setText(QCoreApplication::translate("ParaExportMeshSetup", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParaExportMeshSetup: public Ui_ParaExportMeshSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAEXPORTMESHSETUP_H
