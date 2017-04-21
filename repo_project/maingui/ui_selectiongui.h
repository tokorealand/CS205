/********************************************************************************
** Form generated from reading UI file 'selectiongui.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTIONGUI_H
#define UI_SELECTIONGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectiongui
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *class_2;
    QListWidget *classlist;
    QVBoxLayout *_2;
    QLabel *section;
    QListWidget *sectionlist;
    QVBoxLayout *verticalLayout_3;
    QLabel *student;
    QListWidget *studenlist;
    QVBoxLayout *verticalLayout_4;
    QLabel *lab;
    QListWidget *lablist;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QWidget *selectiongui)
    {
        if (selectiongui->objectName().isEmpty())
            selectiongui->setObjectName(QStringLiteral("selectiongui"));
        selectiongui->resize(1189, 651);
        verticalLayout_2 = new QVBoxLayout(selectiongui);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        class_2 = new QLabel(selectiongui);
        class_2->setObjectName(QStringLiteral("class_2"));

        verticalLayout->addWidget(class_2);

        classlist = new QListWidget(selectiongui);
        classlist->setObjectName(QStringLiteral("classlist"));

        verticalLayout->addWidget(classlist);


        horizontalLayout->addLayout(verticalLayout);

        _2 = new QVBoxLayout();
        _2->setSpacing(6);
        _2->setObjectName(QStringLiteral("_2"));
        section = new QLabel(selectiongui);
        section->setObjectName(QStringLiteral("section"));

        _2->addWidget(section);

        sectionlist = new QListWidget(selectiongui);
        sectionlist->setObjectName(QStringLiteral("sectionlist"));

        _2->addWidget(sectionlist);


        horizontalLayout->addLayout(_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        student = new QLabel(selectiongui);
        student->setObjectName(QStringLiteral("student"));

        verticalLayout_3->addWidget(student);

        studenlist = new QListWidget(selectiongui);
        studenlist->setObjectName(QStringLiteral("studenlist"));

        verticalLayout_3->addWidget(studenlist);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lab = new QLabel(selectiongui);
        lab->setObjectName(QStringLiteral("lab"));

        verticalLayout_4->addWidget(lab);

        lablist = new QListWidget(selectiongui);
        lablist->setObjectName(QStringLiteral("lablist"));

        verticalLayout_4->addWidget(lablist);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(selectiongui);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);

        pushButton = new QPushButton(selectiongui);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        retranslateUi(selectiongui);

        QMetaObject::connectSlotsByName(selectiongui);
    } // setupUi

    void retranslateUi(QWidget *selectiongui)
    {
        selectiongui->setWindowTitle(QApplication::translate("selectiongui", "selectiongui", Q_NULLPTR));
        class_2->setText(QApplication::translate("selectiongui", "Classes", Q_NULLPTR));
        section->setText(QApplication::translate("selectiongui", "Sections", Q_NULLPTR));
        student->setText(QApplication::translate("selectiongui", "Students", Q_NULLPTR));
        lab->setText(QApplication::translate("selectiongui", "Labs", Q_NULLPTR));
        pushButton->setText(QApplication::translate("selectiongui", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class selectiongui: public Ui_selectiongui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTIONGUI_H
