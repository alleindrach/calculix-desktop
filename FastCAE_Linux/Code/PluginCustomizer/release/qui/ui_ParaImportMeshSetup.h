/********************************************************************************
** Form generated from reading UI file 'ParaImportMeshSetup.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAIMPORTMESHSETUP_H
#define UI_PARAIMPORTMESHSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ParaImportMeshSetup
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *chk_selectall;
    QSpacerItem *horizontalSpacer_13;
    QCheckBox *chk_binImport;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chk_cgns;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_22;
    QCheckBox *chk_flunet;
    QSpacerItem *horizontalSpacer_23;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_18;
    QCheckBox *chk_gambit;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_20;
    QCheckBox *chk_stl;
    QSpacerItem *horizontalSpacer_21;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_16;
    QCheckBox *chk_tecplot;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_14;
    QCheckBox *chk_vtk;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *chk_inp;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *chk_cntm;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout;
    QCheckBox *chk_su2;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayout_2;
    QCheckBox *chk_key;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *chk_pdb;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *btnOk;
    QSpacerItem *horizontalSpacer_24;
    QPushButton *btnCancel;

    void setupUi(QDialog *ParaImportMeshSetup)
    {
        if (ParaImportMeshSetup->objectName().isEmpty())
            ParaImportMeshSetup->setObjectName(QString::fromUtf8("ParaImportMeshSetup"));
        ParaImportMeshSetup->resize(366, 466);
        gridLayout_3 = new QGridLayout(ParaImportMeshSetup);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        chk_selectall = new QCheckBox(ParaImportMeshSetup);
        chk_selectall->setObjectName(QString::fromUtf8("chk_selectall"));

        horizontalLayout_8->addWidget(chk_selectall);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);

        chk_binImport = new QCheckBox(ParaImportMeshSetup);
        chk_binImport->setObjectName(QString::fromUtf8("chk_binImport"));

        horizontalLayout_8->addWidget(chk_binImport);


        gridLayout_3->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        chk_cgns = new QCheckBox(ParaImportMeshSetup);
        chk_cgns->setObjectName(QString::fromUtf8("chk_cgns"));
        chk_cgns->setMinimumSize(QSize(110, 0));

        horizontalLayout->addWidget(chk_cgns);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_22);

        chk_flunet = new QCheckBox(ParaImportMeshSetup);
        chk_flunet->setObjectName(QString::fromUtf8("chk_flunet"));
        chk_flunet->setMinimumSize(QSize(110, 0));

        horizontalLayout_13->addWidget(chk_flunet);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_23);


        gridLayout_3->addLayout(horizontalLayout_13, 2, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_18);

        chk_gambit = new QCheckBox(ParaImportMeshSetup);
        chk_gambit->setObjectName(QString::fromUtf8("chk_gambit"));
        chk_gambit->setMinimumSize(QSize(110, 0));

        horizontalLayout_11->addWidget(chk_gambit);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_19);


        gridLayout_3->addLayout(horizontalLayout_11, 3, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_20);

        chk_stl = new QCheckBox(ParaImportMeshSetup);
        chk_stl->setObjectName(QString::fromUtf8("chk_stl"));
        chk_stl->setMinimumSize(QSize(110, 0));

        horizontalLayout_12->addWidget(chk_stl);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_21);


        gridLayout_3->addLayout(horizontalLayout_12, 4, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);

        chk_tecplot = new QCheckBox(ParaImportMeshSetup);
        chk_tecplot->setObjectName(QString::fromUtf8("chk_tecplot"));
        chk_tecplot->setMinimumSize(QSize(110, 0));

        horizontalLayout_10->addWidget(chk_tecplot);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_17);


        gridLayout_3->addLayout(horizontalLayout_10, 5, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);

        chk_vtk = new QCheckBox(ParaImportMeshSetup);
        chk_vtk->setObjectName(QString::fromUtf8("chk_vtk"));
        chk_vtk->setMinimumSize(QSize(110, 0));

        horizontalLayout_9->addWidget(chk_vtk);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_15);


        gridLayout_3->addLayout(horizontalLayout_9, 6, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        chk_inp = new QCheckBox(ParaImportMeshSetup);
        chk_inp->setObjectName(QString::fromUtf8("chk_inp"));
        chk_inp->setMinimumSize(QSize(110, 0));

        horizontalLayout_2->addWidget(chk_inp);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout_3->addLayout(horizontalLayout_2, 7, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        chk_cntm = new QCheckBox(ParaImportMeshSetup);
        chk_cntm->setObjectName(QString::fromUtf8("chk_cntm"));
        chk_cntm->setMinimumSize(QSize(110, 0));

        horizontalLayout_3->addWidget(chk_cntm);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout_3->addLayout(horizontalLayout_3, 8, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        chk_su2 = new QCheckBox(ParaImportMeshSetup);
        chk_su2->setObjectName(QString::fromUtf8("chk_su2"));
        chk_su2->setMinimumSize(QSize(110, 0));

        gridLayout->addWidget(chk_su2, 0, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 0, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 9, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        chk_key = new QCheckBox(ParaImportMeshSetup);
        chk_key->setObjectName(QString::fromUtf8("chk_key"));
        chk_key->setMinimumSize(QSize(110, 0));

        gridLayout_2->addWidget(chk_key, 0, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_11, 0, 2, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_12, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 10, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        chk_pdb = new QCheckBox(ParaImportMeshSetup);
        chk_pdb->setObjectName(QString::fromUtf8("chk_pdb"));
        chk_pdb->setMinimumSize(QSize(110, 0));

        horizontalLayout_4->addWidget(chk_pdb);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        gridLayout_3->addLayout(horizontalLayout_4, 11, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        btnOk = new QPushButton(ParaImportMeshSetup);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_14->addWidget(btnOk);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_24);

        btnCancel = new QPushButton(ParaImportMeshSetup);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_14->addWidget(btnCancel);


        gridLayout_3->addLayout(horizontalLayout_14, 12, 0, 1, 1);


        retranslateUi(ParaImportMeshSetup);

        QMetaObject::connectSlotsByName(ParaImportMeshSetup);
    } // setupUi

    void retranslateUi(QDialog *ParaImportMeshSetup)
    {
        ParaImportMeshSetup->setWindowTitle(QCoreApplication::translate("ParaImportMeshSetup", "Import mesh setup", nullptr));
        chk_selectall->setText(QCoreApplication::translate("ParaImportMeshSetup", "Select all", nullptr));
        chk_binImport->setText(QCoreApplication::translate("ParaImportMeshSetup", "Binary Import", nullptr));
        chk_cgns->setText(QCoreApplication::translate("ParaImportMeshSetup", "CGNS(*.cgns)", nullptr));
        chk_flunet->setText(QCoreApplication::translate("ParaImportMeshSetup", "Flunet(*.msh)", nullptr));
        chk_gambit->setText(QCoreApplication::translate("ParaImportMeshSetup", "Gambit(*.neu)", nullptr));
        chk_stl->setText(QCoreApplication::translate("ParaImportMeshSetup", "STL(*stl)", nullptr));
        chk_tecplot->setText(QCoreApplication::translate("ParaImportMeshSetup", "Tecplot(*.dat)", nullptr));
        chk_vtk->setText(QCoreApplication::translate("ParaImportMeshSetup", "VTK(*.vtk)", nullptr));
        chk_inp->setText(QCoreApplication::translate("ParaImportMeshSetup", "Abaqus(*.inp)", nullptr));
        chk_cntm->setText(QCoreApplication::translate("ParaImportMeshSetup", "CNTM(*.cntm)", nullptr));
        chk_su2->setText(QCoreApplication::translate("ParaImportMeshSetup", "SU2(*.su2)", nullptr));
        chk_key->setText(QCoreApplication::translate("ParaImportMeshSetup", "LS-DYNA(*.key)", nullptr));
        chk_pdb->setText(QCoreApplication::translate("ParaImportMeshSetup", "PDB(*.pdb)", nullptr));
        btnOk->setText(QCoreApplication::translate("ParaImportMeshSetup", "Ok", nullptr));
        btnCancel->setText(QCoreApplication::translate("ParaImportMeshSetup", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParaImportMeshSetup: public Ui_ParaImportMeshSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAIMPORTMESHSETUP_H
