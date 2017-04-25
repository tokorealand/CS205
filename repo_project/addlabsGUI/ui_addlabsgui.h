/********************************************************************************
** Form generated from reading UI file 'addlabsgui.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLABSGUI_H
#define UI_ADDLABSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddLabsGUI
{
public:
    QPushButton *addRubricButton;
    QTextEdit *displayLabs;
    QPushButton *doneButton;
    QPushButton *browseButton;
    QTextEdit *labPathText;
    QPushButton *selectButton;
    QLabel *labPathLabel;
    QLineEdit *browsePath;

    void setupUi(QWidget *AddLabsGUI)
    {
        if (AddLabsGUI->objectName().isEmpty())
            AddLabsGUI->setObjectName(QStringLiteral("AddLabsGUI"));
        AddLabsGUI->resize(490, 465);
        addRubricButton = new QPushButton(AddLabsGUI);
        addRubricButton->setObjectName(QStringLiteral("addRubricButton"));
        addRubricButton->setGeometry(QRect(280, 340, 110, 32));
        displayLabs = new QTextEdit(AddLabsGUI);
        displayLabs->setObjectName(QStringLiteral("displayLabs"));
        displayLabs->setGeometry(QRect(75, 120, 291, 192));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(displayLabs->sizePolicy().hasHeightForWidth());
        displayLabs->setSizePolicy(sizePolicy);
        displayLabs->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        doneButton = new QPushButton(AddLabsGUI);
        doneButton->setObjectName(QStringLiteral("doneButton"));
        doneButton->setGeometry(QRect(12, 425, 74, 32));
        browseButton = new QPushButton(AddLabsGUI);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setGeometry(QRect(370, 80, 99, 32));
        labPathText = new QTextEdit(AddLabsGUI);
        labPathText->setObjectName(QStringLiteral("labPathText"));
        labPathText->setGeometry(QRect(70, 80, 301, 25));
        labPathText->setMaximumSize(QSize(16777215, 25));
        labPathText->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        selectButton = new QPushButton(AddLabsGUI);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        selectButton->setGeometry(QRect(370, 110, 101, 32));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(selectButton->sizePolicy().hasHeightForWidth());
        selectButton->setSizePolicy(sizePolicy1);
        labPathLabel = new QLabel(AddLabsGUI);
        labPathLabel->setObjectName(QStringLiteral("labPathLabel"));
        labPathLabel->setGeometry(QRect(10, 80, 58, 21));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labPathLabel->sizePolicy().hasHeightForWidth());
        labPathLabel->setSizePolicy(sizePolicy2);
        browsePath = new QLineEdit(AddLabsGUI);
        browsePath->setObjectName(QStringLiteral("browsePath"));
        browsePath->setGeometry(QRect(120, 130, 181, 21));
        browsePath->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        retranslateUi(AddLabsGUI);

        QMetaObject::connectSlotsByName(AddLabsGUI);
    } // setupUi

    void retranslateUi(QWidget *AddLabsGUI)
    {
        AddLabsGUI->setWindowTitle(QApplication::translate("AddLabsGUI", "AddLabsGUI", Q_NULLPTR));
        addRubricButton->setText(QApplication::translate("AddLabsGUI", "Add Rubric", Q_NULLPTR));
        doneButton->setText(QApplication::translate("AddLabsGUI", "Done", Q_NULLPTR));
        browseButton->setText(QApplication::translate("AddLabsGUI", "Browse...", Q_NULLPTR));
        selectButton->setText(QApplication::translate("AddLabsGUI", "Select", Q_NULLPTR));
        labPathLabel->setText(QApplication::translate("AddLabsGUI", "Lab Path:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddLabsGUI: public Ui_AddLabsGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLABSGUI_H
