/********************************************************************************
** Form generated from reading UI file 'rubricgui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUBRICGUI_H
#define UI_RUBRICGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RubricGUI
{
public:
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *removeSection;
    QPushButton *createRubric;
    QListWidget *rubricsectionSelect;
    QListWidget *rubricSelect;
    QPushButton *pushButton;
    QLabel *label_8;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpinBox *selectPoints;
    QComboBox *selectColor;
    QTextEdit *selectDescription;
    QPushButton *addSection;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *yearSelect;
    QLabel *label_2;
    QComboBox *semesterSelect;
    QLabel *label_3;
    QComboBox *classSelect;
    QLabel *label_7;
    QSpinBox *selectLab;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QLineEdit *disPoints;
    QPushButton *doneButton;

    void setupUi(QWidget *RubricGUI)
    {
        if (RubricGUI->objectName().isEmpty())
            RubricGUI->setObjectName(QStringLiteral("RubricGUI"));
        RubricGUI->resize(708, 319);
        label_4 = new QLabel(RubricGUI);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(460, 20, 74, 16));
        label_5 = new QLabel(RubricGUI);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(290, 20, 42, 16));
        label_6 = new QLabel(RubricGUI);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 20, 37, 16));
        removeSection = new QPushButton(RubricGUI);
        removeSection->setObjectName(QStringLiteral("removeSection"));
        removeSection->setGeometry(QRect(420, 270, 121, 32));
        createRubric = new QPushButton(RubricGUI);
        createRubric->setObjectName(QStringLiteral("createRubric"));
        createRubric->setGeometry(QRect(30, 270, 121, 32));
        rubricsectionSelect = new QListWidget(RubricGUI);
        rubricsectionSelect->setObjectName(QStringLiteral("rubricsectionSelect"));
        rubricsectionSelect->setGeometry(QRect(290, 70, 401, 201));
        rubricSelect = new QListWidget(RubricGUI);
        rubricSelect->setObjectName(QStringLiteral("rubricSelect"));
        rubricSelect->setGeometry(QRect(190, 70, 91, 201));
        pushButton = new QPushButton(RubricGUI);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 270, 111, 32));
        label_8 = new QLabel(RubricGUI);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 30, 60, 16));
        layoutWidget = new QWidget(RubricGUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 40, 401, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        selectPoints = new QSpinBox(layoutWidget);
        selectPoints->setObjectName(QStringLiteral("selectPoints"));

        horizontalLayout->addWidget(selectPoints);

        selectColor = new QComboBox(layoutWidget);
        selectColor->setObjectName(QStringLiteral("selectColor"));

        horizontalLayout->addWidget(selectColor);

        selectDescription = new QTextEdit(layoutWidget);
        selectDescription->setObjectName(QStringLiteral("selectDescription"));

        horizontalLayout->addWidget(selectDescription);

        addSection = new QPushButton(layoutWidget);
        addSection->setObjectName(QStringLiteral("addSection"));

        horizontalLayout->addWidget(addSection);

        layoutWidget1 = new QWidget(RubricGUI);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 50, 172, 231));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        yearSelect = new QComboBox(layoutWidget1);
        yearSelect->setObjectName(QStringLiteral("yearSelect"));

        gridLayout->addWidget(yearSelect, 0, 1, 1, 2);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        semesterSelect = new QComboBox(layoutWidget1);
        semesterSelect->setObjectName(QStringLiteral("semesterSelect"));

        gridLayout->addWidget(semesterSelect, 1, 1, 1, 2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        classSelect = new QComboBox(layoutWidget1);
        classSelect->setObjectName(QStringLiteral("classSelect"));

        gridLayout->addWidget(classSelect, 2, 1, 1, 2);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 2);

        selectLab = new QSpinBox(layoutWidget1);
        selectLab->setObjectName(QStringLiteral("selectLab"));
        selectLab->setMinimum(1);

        gridLayout->addWidget(selectLab, 3, 2, 1, 1);

        layoutWidget2 = new QWidget(RubricGUI);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(290, 270, 131, 23));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_2->addWidget(label_9);

        disPoints = new QLineEdit(layoutWidget2);
        disPoints->setObjectName(QStringLiteral("disPoints"));

        horizontalLayout_2->addWidget(disPoints);

        doneButton = new QPushButton(RubricGUI);
        doneButton->setObjectName(QStringLiteral("doneButton"));
        doneButton->setGeometry(QRect(580, 270, 113, 32));

        retranslateUi(RubricGUI);

        QMetaObject::connectSlotsByName(RubricGUI);
    } // setupUi

    void retranslateUi(QWidget *RubricGUI)
    {
        RubricGUI->setWindowTitle(QApplication::translate("RubricGUI", "RubricGUI", Q_NULLPTR));
        label_4->setText(QApplication::translate("RubricGUI", "Description:", Q_NULLPTR));
        label_5->setText(QApplication::translate("RubricGUI", "Points:", Q_NULLPTR));
        label_6->setText(QApplication::translate("RubricGUI", "Color:", Q_NULLPTR));
        removeSection->setText(QApplication::translate("RubricGUI", "Remove Section", Q_NULLPTR));
        createRubric->setText(QApplication::translate("RubricGUI", "Create Rubric", Q_NULLPTR));
        pushButton->setText(QApplication::translate("RubricGUI", "Delete Rubric", Q_NULLPTR));
        label_8->setText(QApplication::translate("RubricGUI", "Select:", Q_NULLPTR));
        addSection->setText(QApplication::translate("RubricGUI", "Add Section", Q_NULLPTR));
        label->setText(QApplication::translate("RubricGUI", "Year:", Q_NULLPTR));
        label_2->setText(QApplication::translate("RubricGUI", "Semester:", Q_NULLPTR));
        label_3->setText(QApplication::translate("RubricGUI", "Class:", Q_NULLPTR));
        label_7->setText(QApplication::translate("RubricGUI", "Lab Number:", Q_NULLPTR));
        label_9->setText(QApplication::translate("RubricGUI", "Point Total:", Q_NULLPTR));
        doneButton->setText(QApplication::translate("RubricGUI", "Done", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RubricGUI: public Ui_RubricGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUBRICGUI_H
