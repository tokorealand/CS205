/********************************************************************************
** Form generated from reading UI file 'rubriccreatorgui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUBRICCREATORGUI_H
#define UI_RUBRICCREATORGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RubricCreatorGUI
{
public:
    QListWidget *rubricSectionList;
    QLabel *totalPoints;
    QListWidget *pointValueList;
    QTextEdit *addRubricSectionText;
    QDoubleSpinBox *pointValueSpinBox;
    QLabel *pointValueLabel;
    QLabel *addRubricSectionLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *colorLabel;
    QComboBox *colorDropDown;
    QListWidget *colorList;
    QLabel *totalPointsLabel;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *addSectionButton;
    QPushButton *removeSelectedButton;
    QPushButton *doneButton;

    void setupUi(QWidget *RubricCreatorGUI)
    {
        if (RubricCreatorGUI->objectName().isEmpty())
            RubricCreatorGUI->setObjectName(QStringLiteral("RubricCreatorGUI"));
        RubricCreatorGUI->resize(588, 321);
        rubricSectionList = new QListWidget(RubricCreatorGUI);
        rubricSectionList->setObjectName(QStringLiteral("rubricSectionList"));
        rubricSectionList->setGeometry(QRect(11, 59, 239, 251));
        totalPoints = new QLabel(RubricCreatorGUI);
        totalPoints->setObjectName(QStringLiteral("totalPoints"));
        totalPoints->setGeometry(QRect(470, 280, 47, 13));
        pointValueList = new QListWidget(RubricCreatorGUI);
        pointValueList->setObjectName(QStringLiteral("pointValueList"));
        pointValueList->setGeometry(QRect(271, 56, 81, 254));
        addRubricSectionText = new QTextEdit(RubricCreatorGUI);
        addRubricSectionText->setObjectName(QStringLiteral("addRubricSectionText"));
        addRubricSectionText->setGeometry(QRect(11, 30, 239, 21));
        addRubricSectionText->setMaximumSize(QSize(16777215, 189));
        pointValueSpinBox = new QDoubleSpinBox(RubricCreatorGUI);
        pointValueSpinBox->setObjectName(QStringLiteral("pointValueSpinBox"));
        pointValueSpinBox->setGeometry(QRect(271, 30, 81, 20));
        pointValueLabel = new QLabel(RubricCreatorGUI);
        pointValueLabel->setObjectName(QStringLiteral("pointValueLabel"));
        pointValueLabel->setGeometry(QRect(271, 11, 71, 16));
        addRubricSectionLabel = new QLabel(RubricCreatorGUI);
        addRubricSectionLabel->setObjectName(QStringLiteral("addRubricSectionLabel"));
        addRubricSectionLabel->setGeometry(QRect(11, 11, 151, 16));
        layoutWidget = new QWidget(RubricCreatorGUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(370, 10, 77, 301));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        colorLabel = new QLabel(layoutWidget);
        colorLabel->setObjectName(QStringLiteral("colorLabel"));

        verticalLayout->addWidget(colorLabel);

        colorDropDown = new QComboBox(layoutWidget);
        colorDropDown->setObjectName(QStringLiteral("colorDropDown"));

        verticalLayout->addWidget(colorDropDown);


        verticalLayout_2->addLayout(verticalLayout);

        colorList = new QListWidget(layoutWidget);
        colorList->setObjectName(QStringLiteral("colorList"));

        verticalLayout_2->addWidget(colorList);

        totalPointsLabel = new QLabel(RubricCreatorGUI);
        totalPointsLabel->setObjectName(QStringLiteral("totalPointsLabel"));
        totalPointsLabel->setGeometry(QRect(470, 260, 71, 16));
        layoutWidget_2 = new QWidget(RubricCreatorGUI);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(460, 120, 115, 83));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        addSectionButton = new QPushButton(layoutWidget_2);
        addSectionButton->setObjectName(QStringLiteral("addSectionButton"));

        verticalLayout_4->addWidget(addSectionButton);

        removeSelectedButton = new QPushButton(layoutWidget_2);
        removeSelectedButton->setObjectName(QStringLiteral("removeSelectedButton"));

        verticalLayout_4->addWidget(removeSelectedButton);

        doneButton = new QPushButton(layoutWidget_2);
        doneButton->setObjectName(QStringLiteral("doneButton"));

        verticalLayout_4->addWidget(doneButton);


        retranslateUi(RubricCreatorGUI);

        QMetaObject::connectSlotsByName(RubricCreatorGUI);
    } // setupUi

    void retranslateUi(QWidget *RubricCreatorGUI)
    {
        RubricCreatorGUI->setWindowTitle(QApplication::translate("RubricCreatorGUI", "RubricCreatorGUI", Q_NULLPTR));
        totalPoints->setText(QString());
        pointValueLabel->setText(QApplication::translate("RubricCreatorGUI", "Point Value:", Q_NULLPTR));
        addRubricSectionLabel->setText(QApplication::translate("RubricCreatorGUI", "Add a rubric section:", Q_NULLPTR));
        colorLabel->setText(QApplication::translate("RubricCreatorGUI", "Color:", Q_NULLPTR));
        colorDropDown->clear();
        colorDropDown->insertItems(0, QStringList()
         << QApplication::translate("RubricCreatorGUI", "red", Q_NULLPTR)
         << QApplication::translate("RubricCreatorGUI", "blue", Q_NULLPTR)
         << QApplication::translate("RubricCreatorGUI", "green", Q_NULLPTR)
         << QApplication::translate("RubricCreatorGUI", "purple", Q_NULLPTR)
         << QApplication::translate("RubricCreatorGUI", "orange", Q_NULLPTR)
         << QApplication::translate("RubricCreatorGUI", "pink", Q_NULLPTR)
        );
        totalPointsLabel->setText(QApplication::translate("RubricCreatorGUI", "Total Points:", Q_NULLPTR));
        addSectionButton->setText(QApplication::translate("RubricCreatorGUI", "Add Section", Q_NULLPTR));
        removeSelectedButton->setText(QApplication::translate("RubricCreatorGUI", "Remove Selected", Q_NULLPTR));
        doneButton->setText(QApplication::translate("RubricCreatorGUI", "Done", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RubricCreatorGUI: public Ui_RubricCreatorGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUBRICCREATORGUI_H
