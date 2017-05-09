/********************************************************************************
** Form generated from reading UI file 'labviewgui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABVIEWGUI_H
#define UI_LABVIEWGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_labViewGUI
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *displayJavaClasses;
    QTextEdit *displayJavaText;

    void setupUi(QWidget *labViewGUI)
    {
        if (labViewGUI->objectName().isEmpty())
            labViewGUI->setObjectName(QStringLiteral("labViewGUI"));
        labViewGUI->resize(670, 496);
        horizontalLayout = new QHBoxLayout(labViewGUI);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(labViewGUI);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        displayJavaClasses = new QTextEdit(labViewGUI);
        displayJavaClasses->setObjectName(QStringLiteral("displayJavaClasses"));
        displayJavaClasses->setReadOnly(true);

        verticalLayout->addWidget(displayJavaClasses);


        horizontalLayout->addLayout(verticalLayout);

        displayJavaText = new QTextEdit(labViewGUI);
        displayJavaText->setObjectName(QStringLiteral("displayJavaText"));
        displayJavaText->setReadOnly(true);

        horizontalLayout->addWidget(displayJavaText);


        retranslateUi(labViewGUI);

        QMetaObject::connectSlotsByName(labViewGUI);
    } // setupUi

    void retranslateUi(QWidget *labViewGUI)
    {
        labViewGUI->setWindowTitle(QApplication::translate("labViewGUI", "labViewGUI", Q_NULLPTR));
        label->setText(QApplication::translate("labViewGUI", "Classes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class labViewGUI: public Ui_labViewGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABVIEWGUI_H
