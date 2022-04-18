/********************************************************************************
** Form generated from reading UI file 'dialogVariableFillet.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGVARIABLEFILLET_H
#define UI_DIALOGVARIABLEFILLET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VariableFilletDialog
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *edgelabel;
    QPushButton *geoSelectCurve;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditRadius;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonAdd;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QTableWidget *tableLR;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *removeButton;
    QWidget *widgetAdd;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditLocation;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditRadiusNew;
    QLabel *label_7;
    QPushButton *addLR;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *VariableFilletDialog)
    {
        if (VariableFilletDialog->objectName().isEmpty())
            VariableFilletDialog->setObjectName(QString::fromUtf8("VariableFilletDialog"));
        VariableFilletDialog->resize(449, 547);
        gridLayout_4 = new QGridLayout(VariableFilletDialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(VariableFilletDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        edgelabel = new QLabel(groupBox);
        edgelabel->setObjectName(QString::fromUtf8("edgelabel"));

        gridLayout->addWidget(edgelabel, 0, 0, 1, 1);

        geoSelectCurve = new QPushButton(groupBox);
        geoSelectCurve->setObjectName(QString::fromUtf8("geoSelectCurve"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(geoSelectCurve->sizePolicy().hasHeightForWidth());
        geoSelectCurve->setSizePolicy(sizePolicy);
        geoSelectCurve->setMinimumSize(QSize(32, 32));
        geoSelectCurve->setMaximumSize(QSize(32, 32));
        geoSelectCurve->setStyleSheet(QString::fromUtf8("background-image: url(:/QUI/geometry/selectwire.png);"));
        geoSelectCurve->setCheckable(true);
        geoSelectCurve->setChecked(false);

        gridLayout->addWidget(geoSelectCurve, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(VariableFilletDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditRadius = new QLineEdit(groupBox_2);
        lineEditRadius->setObjectName(QString::fromUtf8("lineEditRadius"));

        horizontalLayout_3->addWidget(lineEditRadius);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(VariableFilletDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        buttonAdd = new QPushButton(VariableFilletDialog);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonAdd->sizePolicy().hasHeightForWidth());
        buttonAdd->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(buttonAdd);


        gridLayout_4->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(VariableFilletDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tableLR = new QTableWidget(groupBox_3);
        if (tableLR->columnCount() < 2)
            tableLR->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableLR->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableLR->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableLR->setObjectName(QString::fromUtf8("tableLR"));

        gridLayout_5->addWidget(tableLR, 0, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(370, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        removeButton = new QPushButton(groupBox_3);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setStyleSheet(QString::fromUtf8("background-image: url(:/QUI/geometry/remove.png);"));

        gridLayout_5->addWidget(removeButton, 1, 1, 1, 1);

        widgetAdd = new QWidget(groupBox_3);
        widgetAdd->setObjectName(QString::fromUtf8("widgetAdd"));
        gridLayout_3 = new QGridLayout(widgetAdd);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(widgetAdd);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(widgetAdd);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEditLocation = new QLineEdit(widgetAdd);
        lineEditLocation->setObjectName(QString::fromUtf8("lineEditLocation"));

        verticalLayout_2->addWidget(lineEditLocation);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditRadiusNew = new QLineEdit(widgetAdd);
        lineEditRadiusNew->setObjectName(QString::fromUtf8("lineEditRadiusNew"));

        horizontalLayout->addWidget(lineEditRadiusNew);

        label_7 = new QLabel(widgetAdd);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        addLR = new QPushButton(widgetAdd);
        addLR->setObjectName(QString::fromUtf8("addLR"));

        gridLayout_3->addWidget(addLR, 0, 1, 1, 1);


        gridLayout_5->addWidget(widgetAdd, 2, 0, 1, 2);


        gridLayout_4->addWidget(groupBox_3, 3, 0, 1, 1);

        buttonBox = new QDialogButtonBox(VariableFilletDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_4->addWidget(buttonBox, 4, 0, 1, 1);


        retranslateUi(VariableFilletDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), VariableFilletDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), VariableFilletDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(VariableFilletDialog);
    } // setupUi

    void retranslateUi(QDialog *VariableFilletDialog)
    {
        VariableFilletDialog->setWindowTitle(QCoreApplication::translate("VariableFilletDialog", "Variable Fillet", nullptr));
        groupBox->setTitle(QCoreApplication::translate("VariableFilletDialog", "Edge", nullptr));
        edgelabel->setText(QCoreApplication::translate("VariableFilletDialog", "Selected edge(0)", nullptr));
        geoSelectCurve->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("VariableFilletDialog", "Radius", nullptr));
        label_3->setText(QCoreApplication::translate("VariableFilletDialog", "Radius:", nullptr));
        lineEditRadius->setText(QCoreApplication::translate("VariableFilletDialog", "1.00", nullptr));
        label_6->setText(QCoreApplication::translate("VariableFilletDialog", "mm", nullptr));
        label->setText(QCoreApplication::translate("VariableFilletDialog", "Add Variable Point:", nullptr));
        buttonAdd->setText(QCoreApplication::translate("VariableFilletDialog", "Add", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("VariableFilletDialog", "Table", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableLR->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("VariableFilletDialog", "Location", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableLR->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("VariableFilletDialog", "Radius", nullptr));
        removeButton->setText(QString());
        label_2->setText(QCoreApplication::translate("VariableFilletDialog", "Location(u):", nullptr));
        label_4->setText(QCoreApplication::translate("VariableFilletDialog", "Radius:", nullptr));
        lineEditLocation->setText(QCoreApplication::translate("VariableFilletDialog", "0.00", nullptr));
        lineEditRadiusNew->setText(QCoreApplication::translate("VariableFilletDialog", "1.00", nullptr));
        label_7->setText(QCoreApplication::translate("VariableFilletDialog", "mm", nullptr));
        addLR->setText(QCoreApplication::translate("VariableFilletDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VariableFilletDialog: public Ui_VariableFilletDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGVARIABLEFILLET_H
