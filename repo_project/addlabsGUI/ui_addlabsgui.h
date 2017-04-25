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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddLabsGUI
{
public:
    QFormLayout *formLayout;
    QLabel *labPathLabel;
    QHBoxLayout *horizontalLayout;
    QTextEdit *labPathText;
    QPushButton *browseButton;
    QPushButton *selectButton;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *displayLabs;
    QPushButton *addRubricButton;
    QLineEdit *browsePath;
    QPushButton *doneButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AddLabsGUI)
    {
        if (AddLabsGUI->objectName().isEmpty())
            AddLabsGUI->setObjectName(QStringLiteral("AddLabsGUI"));
        AddLabsGUI->resize(1073, 515);
        AddLabsGUI->setStyleSheet(QStringLiteral(""));
        formLayout = new QFormLayout(AddLabsGUI);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labPathLabel = new QLabel(AddLabsGUI);
        labPathLabel->setObjectName(QStringLiteral("labPathLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labPathLabel->sizePolicy().hasHeightForWidth());
        labPathLabel->setSizePolicy(sizePolicy);
        labPathLabel->setMaximumSize(QSize(1000, 16777215));

        formLayout->setWidget(1, QFormLayout::LabelRole, labPathLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labPathText = new QTextEdit(AddLabsGUI);
        labPathText->setObjectName(QStringLiteral("labPathText"));
        labPathText->setMaximumSize(QSize(1000, 25));
        labPathText->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(labPathText);

        browseButton = new QPushButton(AddLabsGUI);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setMaximumSize(QSize(1000, 16777215));

        horizontalLayout->addWidget(browseButton);

        selectButton = new QPushButton(AddLabsGUI);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(selectButton->sizePolicy().hasHeightForWidth());
        selectButton->setSizePolicy(sizePolicy1);
        selectButton->setMaximumSize(QSize(1000, 16777215));

        horizontalLayout->addWidget(selectButton);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        displayLabs = new QTextEdit(AddLabsGUI);
        displayLabs->setObjectName(QStringLiteral("displayLabs"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(displayLabs->sizePolicy().hasHeightForWidth());
        displayLabs->setSizePolicy(sizePolicy2);
        displayLabs->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(displayLabs);

        addRubricButton = new QPushButton(AddLabsGUI);
        addRubricButton->setObjectName(QStringLiteral("addRubricButton"));

        horizontalLayout_2->addWidget(addRubricButton);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_2);

        browsePath = new QLineEdit(AddLabsGUI);
        browsePath->setObjectName(QStringLiteral("browsePath"));
        browsePath->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(6, QFormLayout::FieldRole, browsePath);

        doneButton = new QPushButton(AddLabsGUI);
        doneButton->setObjectName(QStringLiteral("doneButton"));

        formLayout->setWidget(7, QFormLayout::FieldRole, doneButton);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer);


        retranslateUi(AddLabsGUI);

        QMetaObject::connectSlotsByName(AddLabsGUI);
    } // setupUi

    void retranslateUi(QWidget *AddLabsGUI)
    {
        AddLabsGUI->setWindowTitle(QApplication::translate("AddLabsGUI", "AddLabsGUI", Q_NULLPTR));
        labPathLabel->setText(QApplication::translate("AddLabsGUI", "Lab Path:", Q_NULLPTR));
        browseButton->setText(QApplication::translate("AddLabsGUI", "Browse...", Q_NULLPTR));
        selectButton->setText(QApplication::translate("AddLabsGUI", "Select", Q_NULLPTR));
        addRubricButton->setText(QApplication::translate("AddLabsGUI", "Add Rubric", Q_NULLPTR));
        doneButton->setText(QApplication::translate("AddLabsGUI", "Done", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddLabsGUI: public Ui_AddLabsGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLABSGUI_H
