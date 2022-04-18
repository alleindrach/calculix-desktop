/********************************************************************************
** Form generated from reading UI file 'dialogMakeFillGap.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMAKEFILLGAP_H
#define UI_DIALOGMAKEFILLGAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogFillGap
{
public:
    QGridLayout *gridLayout_3;
    QComboBox *comboBoxType;
    QLabel *label_5;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QLabel *topedgelabel_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *geoSelectCurve;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QLabel *topedgelabel_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *geoSelectSurface_1;
    QWidget *tab_4;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *topedgelabel_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *geoSelectSurface;

    void setupUi(QDialog *DialogFillGap)
    {
        if (DialogFillGap->objectName().isEmpty())
            DialogFillGap->setObjectName(QString::fromUtf8("DialogFillGap"));
        DialogFillGap->resize(330, 182);
        gridLayout_3 = new QGridLayout(DialogFillGap);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        comboBoxType = new QComboBox(DialogFillGap);
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->setObjectName(QString::fromUtf8("comboBoxType"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxType->sizePolicy().hasHeightForWidth());
        comboBoxType->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(comboBoxType, 0, 1, 1, 1);

        label_5 = new QLabel(DialogFillGap);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogFillGap);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 2, 0, 1, 2);

        tabWidget = new QTabWidget(DialogFillGap);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        topedgelabel_2 = new QLabel(tab_2);
        topedgelabel_2->setObjectName(QString::fromUtf8("topedgelabel_2"));

        gridLayout_4->addWidget(topedgelabel_2, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(107, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        geoSelectCurve = new QPushButton(tab_2);
        geoSelectCurve->setObjectName(QString::fromUtf8("geoSelectCurve"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(geoSelectCurve->sizePolicy().hasHeightForWidth());
        geoSelectCurve->setSizePolicy(sizePolicy2);
        geoSelectCurve->setMinimumSize(QSize(32, 32));
        geoSelectCurve->setMaximumSize(QSize(32, 32));
        geoSelectCurve->setStyleSheet(QString::fromUtf8("background-image: url(:/QUI/geometry/selectwire.png);"));
        geoSelectCurve->setCheckable(true);

        gridLayout_4->addWidget(geoSelectCurve, 0, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        topedgelabel_3 = new QLabel(tab_3);
        topedgelabel_3->setObjectName(QString::fromUtf8("topedgelabel_3"));

        gridLayout_2->addWidget(topedgelabel_3, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(107, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        geoSelectSurface_1 = new QPushButton(tab_3);
        geoSelectSurface_1->setObjectName(QString::fromUtf8("geoSelectSurface_1"));
        sizePolicy2.setHeightForWidth(geoSelectSurface_1->sizePolicy().hasHeightForWidth());
        geoSelectSurface_1->setSizePolicy(sizePolicy2);
        geoSelectSurface_1->setMinimumSize(QSize(32, 32));
        geoSelectSurface_1->setMaximumSize(QSize(32, 32));
        geoSelectSurface_1->setStyleSheet(QString::fromUtf8("background-image: url(:/QUI/geometry/selectface.png);"));
        geoSelectSurface_1->setCheckable(true);

        gridLayout_2->addWidget(geoSelectSurface_1, 0, 2, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout = new QGridLayout(tab_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        topedgelabel_4 = new QLabel(tab_4);
        topedgelabel_4->setObjectName(QString::fromUtf8("topedgelabel_4"));

        horizontalLayout->addWidget(topedgelabel_4);

        horizontalSpacer_5 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        geoSelectSurface = new QPushButton(tab_4);
        geoSelectSurface->setObjectName(QString::fromUtf8("geoSelectSurface"));
        sizePolicy2.setHeightForWidth(geoSelectSurface->sizePolicy().hasHeightForWidth());
        geoSelectSurface->setSizePolicy(sizePolicy2);
        geoSelectSurface->setMinimumSize(QSize(32, 32));
        geoSelectSurface->setMaximumSize(QSize(32, 32));
        geoSelectSurface->setStyleSheet(QString::fromUtf8("background-image: url(:/QUI/geometry/selectbody.png);"));
        geoSelectSurface->setCheckable(true);

        horizontalLayout->addWidget(geoSelectSurface);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        gridLayout_3->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(DialogFillGap);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogFillGap, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogFillGap, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogFillGap);
    } // setupUi

    void retranslateUi(QDialog *DialogFillGap)
    {
        DialogFillGap->setWindowTitle(QCoreApplication::translate("DialogFillGap", "DialogFillGap", nullptr));
        comboBoxType->setItemText(0, QCoreApplication::translate("DialogFillGap", "Edge", nullptr));
        comboBoxType->setItemText(1, QCoreApplication::translate("DialogFillGap", "Surface", nullptr));
        comboBoxType->setItemText(2, QCoreApplication::translate("DialogFillGap", "Solid", nullptr));

        label_5->setText(QCoreApplication::translate("DialogFillGap", "Please Select", nullptr));
        topedgelabel_2->setText(QCoreApplication::translate("DialogFillGap", "Selected Object(0)", nullptr));
        geoSelectCurve->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DialogFillGap", "Tab 2", nullptr));
        topedgelabel_3->setText(QCoreApplication::translate("DialogFillGap", "Selected Object(0)", nullptr));
        geoSelectSurface_1->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("DialogFillGap", "\351\241\265", nullptr));
        topedgelabel_4->setText(QCoreApplication::translate("DialogFillGap", "Selected Object(0)", nullptr));
        geoSelectSurface->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("DialogFillGap", "\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFillGap: public Ui_DialogFillGap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMAKEFILLGAP_H
