/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_Random_Lab;
    QAction *actionAdd_New_Lab;
    QAction *actionAdd_Students;
    QAction *actionComment;
    QAction *actionHighlight;
    QAction *actionLab;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuExisting_Labs;
    QMenu *menuGrade;
    QMenu *menuGrading_Tools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(502, 391);
        actionLoad_Random_Lab = new QAction(MainWindow);
        actionLoad_Random_Lab->setObjectName(QStringLiteral("actionLoad_Random_Lab"));
        actionAdd_New_Lab = new QAction(MainWindow);
        actionAdd_New_Lab->setObjectName(QStringLiteral("actionAdd_New_Lab"));
        actionAdd_Students = new QAction(MainWindow);
        actionAdd_Students->setObjectName(QStringLiteral("actionAdd_Students"));
        actionComment = new QAction(MainWindow);
        actionComment->setObjectName(QStringLiteral("actionComment"));
        actionHighlight = new QAction(MainWindow);
        actionHighlight->setObjectName(QStringLiteral("actionHighlight"));
        actionLab = new QAction(MainWindow);
        actionLab->setObjectName(QStringLiteral("actionLab"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 310, 461, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        horizontalLayout_2->addLayout(horizontalLayout);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_2->addWidget(checkBox);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 491, 301));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        listWidget = new QListWidget(tab);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 221, 261));
        listWidget_2 = new QListWidget(tab);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(250, 10, 221, 261));
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 502, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuExisting_Labs = new QMenu(menuFile);
        menuExisting_Labs->setObjectName(QStringLiteral("menuExisting_Labs"));
        menuGrade = new QMenu(menuBar);
        menuGrade->setObjectName(QStringLiteral("menuGrade"));
        menuGrading_Tools = new QMenu(menuBar);
        menuGrading_Tools->setObjectName(QStringLiteral("menuGrading_Tools"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuGrade->menuAction());
        menuBar->addAction(menuGrading_Tools->menuAction());
        menuFile->addAction(menuExisting_Labs->menuAction());
        menuFile->addAction(actionAdd_New_Lab);
        menuFile->addAction(actionAdd_Students);
        menuExisting_Labs->addAction(actionLab);
        menuGrade->addAction(actionLoad_Random_Lab);
        menuGrading_Tools->addAction(actionComment);
        menuGrading_Tools->addAction(actionHighlight);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLoad_Random_Lab->setText(QApplication::translate("MainWindow", "Load Random Lab", 0));
        actionAdd_New_Lab->setText(QApplication::translate("MainWindow", "Add New Lab", 0));
        actionAdd_Students->setText(QApplication::translate("MainWindow", "Add Students ", 0));
        actionComment->setText(QApplication::translate("MainWindow", "Comment", 0));
        actionHighlight->setText(QApplication::translate("MainWindow", "Highlight", 0));
        actionLab->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Current Lab: ", 0));
        label_2->setText(QApplication::translate("MainWindow", "None", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Finished Grading", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuExisting_Labs->setTitle(QApplication::translate("MainWindow", "Existing Labs", 0));
        menuGrade->setTitle(QApplication::translate("MainWindow", "Grade", 0));
        menuGrading_Tools->setTitle(QApplication::translate("MainWindow", "Grading Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
