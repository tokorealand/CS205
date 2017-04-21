/********************************************************************************
** Form generated from reading UI file 'gradebookgui.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADEBOOKGUI_H
#define UI_GRADEBOOKGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GradeBookGUI
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QComboBox *comboBox_3;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QLabel *label_3;
    QComboBox *comboBox_5;

    void setupUi(QWidget *GradeBookGUI)
    {
        if (GradeBookGUI->objectName().isEmpty())
            GradeBookGUI->setObjectName(QStringLiteral("GradeBookGUI"));
        GradeBookGUI->resize(571, 341);
        tableWidget = new QTableWidget(GradeBookGUI);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(190, 70, 371, 221));
        pushButton = new QPushButton(GradeBookGUI);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 300, 113, 32));
        pushButton_2 = new QPushButton(GradeBookGUI);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 300, 141, 32));
        widget = new QWidget(GradeBookGUI);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(3, 70, 172, 221));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox_3 = new QComboBox(widget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        gridLayout->addWidget(comboBox_3, 1, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        comboBox_4 = new QComboBox(widget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        gridLayout->addWidget(comboBox_4, 2, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        comboBox_5 = new QComboBox(widget);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        gridLayout->addWidget(comboBox_5, 3, 1, 1, 1);


        retranslateUi(GradeBookGUI);

        QMetaObject::connectSlotsByName(GradeBookGUI);
    } // setupUi

    void retranslateUi(QWidget *GradeBookGUI)
    {
        GradeBookGUI->setWindowTitle(QApplication::translate("GradeBookGUI", "GradeBookGUI", Q_NULLPTR));
        pushButton->setText(QApplication::translate("GradeBookGUI", "Close", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("GradeBookGUI", "Display Statistics", Q_NULLPTR));
        label->setText(QApplication::translate("GradeBookGUI", "Year:", Q_NULLPTR));
        label_2->setText(QApplication::translate("GradeBookGUI", "Semseter:", Q_NULLPTR));
        label_4->setText(QApplication::translate("GradeBookGUI", "Section:", Q_NULLPTR));
        label_3->setText(QApplication::translate("GradeBookGUI", "Class:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GradeBookGUI: public Ui_GradeBookGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADEBOOKGUI_H
