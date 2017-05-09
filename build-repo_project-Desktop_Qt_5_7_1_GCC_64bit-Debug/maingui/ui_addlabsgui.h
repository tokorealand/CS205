/********************************************************************************
** Form generated from reading UI file 'addlabsgui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddLabsGUI
{
public:
    QPushButton *browseButton;
    QTextEdit *labPathText;
    QPushButton *selectButton;
    QLabel *labPathLabel;

    void setupUi(QWidget *AddLabsGUI)
    {
        if (AddLabsGUI->objectName().isEmpty())
            AddLabsGUI->setObjectName(QStringLiteral("AddLabsGUI"));
        AddLabsGUI->resize(490, 161);
        AddLabsGUI->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        browseButton = new QPushButton(AddLabsGUI);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setGeometry(QRect(380, 80, 99, 32));
        labPathText = new QTextEdit(AddLabsGUI);
        labPathText->setObjectName(QStringLiteral("labPathText"));
        labPathText->setGeometry(QRect(70, 80, 301, 25));
        labPathText->setMaximumSize(QSize(16777215, 25));
        labPathText->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        selectButton = new QPushButton(AddLabsGUI);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        selectButton->setGeometry(QRect(380, 120, 101, 32));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectButton->sizePolicy().hasHeightForWidth());
        selectButton->setSizePolicy(sizePolicy);
        selectButton->setAutoDefault(false);
        labPathLabel = new QLabel(AddLabsGUI);
        labPathLabel->setObjectName(QStringLiteral("labPathLabel"));
        labPathLabel->setGeometry(QRect(10, 80, 58, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labPathLabel->sizePolicy().hasHeightForWidth());
        labPathLabel->setSizePolicy(sizePolicy1);

        retranslateUi(AddLabsGUI);

        QMetaObject::connectSlotsByName(AddLabsGUI);
    } // setupUi

    void retranslateUi(QWidget *AddLabsGUI)
    {
        AddLabsGUI->setWindowTitle(QApplication::translate("AddLabsGUI", "AddLabsGUI", Q_NULLPTR));
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
