/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_New_Lab;
    QAction *actionSample;
    QAction *actionAdd_Students;
    QAction *actionAnother_Lab;
    QAction *actionComment;
    QAction *actionHighlight;
    QAction *actionLoad_Lab;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *years;
    QComboBox *semesters;
    QListWidget *classlist;
    QListWidget *sectionlist;
    QListWidget *studentlist;
    QListWidget *lablist;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_3;
    QListWidget *disjava;
    QPushButton *displayButton;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *currentLabLabel;
    QLabel *currentLab;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox;
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
        MainWindow->resize(822, 655);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(134, 134, 134);"));
        actionLoad_New_Lab = new QAction(MainWindow);
        actionLoad_New_Lab->setObjectName(QStringLiteral("actionLoad_New_Lab"));
        actionSample = new QAction(MainWindow);
        actionSample->setObjectName(QStringLiteral("actionSample"));
        actionAdd_Students = new QAction(MainWindow);
        actionAdd_Students->setObjectName(QStringLiteral("actionAdd_Students"));
        actionAnother_Lab = new QAction(MainWindow);
        actionAnother_Lab->setObjectName(QStringLiteral("actionAnother_Lab"));
        actionComment = new QAction(MainWindow);
        actionComment->setObjectName(QStringLiteral("actionComment"));
        actionHighlight = new QAction(MainWindow);
        actionHighlight->setObjectName(QStringLiteral("actionHighlight"));
        actionLoad_Lab = new QAction(MainWindow);
        actionLoad_Lab->setObjectName(QStringLiteral("actionLoad_Lab"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        years = new QComboBox(tab);
        years->setObjectName(QStringLiteral("years"));
        years->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(years);

        semesters = new QComboBox(tab);
        semesters->setObjectName(QStringLiteral("semesters"));
        semesters->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(semesters);

        classlist = new QListWidget(tab);
        classlist->setObjectName(QStringLiteral("classlist"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(classlist->sizePolicy().hasHeightForWidth());
        classlist->setSizePolicy(sizePolicy);
        classlist->setMaximumSize(QSize(150, 16777215));
        classlist->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(classlist);

        sectionlist = new QListWidget(tab);
        sectionlist->setObjectName(QStringLiteral("sectionlist"));
        sizePolicy.setHeightForWidth(sectionlist->sizePolicy().hasHeightForWidth());
        sectionlist->setSizePolicy(sizePolicy);
        sectionlist->setMaximumSize(QSize(150, 16777215));
        sectionlist->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(sectionlist);

        studentlist = new QListWidget(tab);
        studentlist->setObjectName(QStringLiteral("studentlist"));
        sizePolicy.setHeightForWidth(studentlist->sizePolicy().hasHeightForWidth());
        studentlist->setSizePolicy(sizePolicy);
        studentlist->setMaximumSize(QSize(150, 16777215));
        studentlist->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(studentlist);

        lablist = new QListWidget(tab);
        lablist->setObjectName(QStringLiteral("lablist"));
        sizePolicy.setHeightForWidth(lablist->sizePolicy().hasHeightForWidth());
        lablist->setSizePolicy(sizePolicy);
        lablist->setMaximumSize(QSize(150, 16777215));
        lablist->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(lablist);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        disjava = new QListWidget(tab);
        disjava->setObjectName(QStringLiteral("disjava"));
        disjava->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(disjava);

        displayButton = new QPushButton(tab);
        displayButton->setObjectName(QStringLiteral("displayButton"));

        verticalLayout_3->addWidget(displayButton);


        horizontalLayout_3->addLayout(verticalLayout_3);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        currentLabLabel = new QLabel(centralWidget);
        currentLabLabel->setObjectName(QStringLiteral("currentLabLabel"));

        horizontalLayout->addWidget(currentLabLabel);

        currentLab = new QLabel(centralWidget);
        currentLab->setObjectName(QStringLiteral("currentLab"));

        horizontalLayout->addWidget(currentLab);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        horizontalLayout_2->addLayout(horizontalLayout);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_2->addWidget(checkBox);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 822, 22));
        menuBar->setNativeMenuBar(false);
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
        menuFile->addAction(actionLoad_New_Lab);
        menuGrade->addAction(actionAnother_Lab);
        menuGrade->addAction(actionLoad_Lab);
        menuGrading_Tools->addAction(actionComment);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionLoad_New_Lab->setText(QApplication::translate("MainWindow", "Add New Labs", Q_NULLPTR));
        actionSample->setText(QApplication::translate("MainWindow", "sample", Q_NULLPTR));
        actionAdd_Students->setText(QApplication::translate("MainWindow", "Add Students", Q_NULLPTR));
        actionAnother_Lab->setText(QApplication::translate("MainWindow", "Load Random Lab", Q_NULLPTR));
        actionComment->setText(QApplication::translate("MainWindow", "Comment", Q_NULLPTR));
        actionHighlight->setText(QApplication::translate("MainWindow", "Highlight", Q_NULLPTR));
        actionLoad_Lab->setText(QApplication::translate("MainWindow", "Load Lab", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Selection", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Save|Exit", Q_NULLPTR));
        displayButton->setText(QApplication::translate("MainWindow", "Display", Q_NULLPTR));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        currentLabLabel->setText(QApplication::translate("MainWindow", "Current Lab: ", Q_NULLPTR));
        currentLab->setText(QApplication::translate("MainWindow", "None", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Finished Grading", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuExisting_Labs->setTitle(QApplication::translate("MainWindow", "Existing Labs", Q_NULLPTR));
        menuGrade->setTitle(QApplication::translate("MainWindow", "Grade", Q_NULLPTR));
        menuGrading_Tools->setTitle(QApplication::translate("MainWindow", "Grading Tools", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
