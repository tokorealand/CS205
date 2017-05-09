/********************************************************************************
** Form generated from reading UI file 'mainmenugui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUGUI_H
#define UI_MAINMENUGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuGUI
{
public:
    QAction *actionAdd_New_Labs;
    QAction *actionComment;
    QAction *actionExport_Lab;
    QAction *actionAdd_Rubric;
    QAction *actionCalculate_Stats;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QListWidget *componentSelect;
    QVBoxLayout *verticalLayout_4;
    QPushButton *Refresh;
    QListWidget *disjava;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QListWidget *disrubric;
    QLabel *label_11;
    QListWidget *discomment;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *displayLabGrade;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QComboBox *yearSelect;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *semesterSelect;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *classSelect;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QComboBox *sectionSelect;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QComboBox *studentSelect;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QComboBox *labSelect;
    QPushButton *saveAndExit;
    QPushButton *deleteComment;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainMenuGUI)
    {
        if (MainMenuGUI->objectName().isEmpty())
            MainMenuGUI->setObjectName(QStringLiteral("MainMenuGUI"));
        MainMenuGUI->resize(1283, 747);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainMenuGUI->sizePolicy().hasHeightForWidth());
        MainMenuGUI->setSizePolicy(sizePolicy);
        actionAdd_New_Labs = new QAction(MainMenuGUI);
        actionAdd_New_Labs->setObjectName(QStringLiteral("actionAdd_New_Labs"));
        actionComment = new QAction(MainMenuGUI);
        actionComment->setObjectName(QStringLiteral("actionComment"));
        actionExport_Lab = new QAction(MainMenuGUI);
        actionExport_Lab->setObjectName(QStringLiteral("actionExport_Lab"));
        actionAdd_Rubric = new QAction(MainMenuGUI);
        actionAdd_Rubric->setObjectName(QStringLiteral("actionAdd_Rubric"));
        actionCalculate_Stats = new QAction(MainMenuGUI);
        actionCalculate_Stats->setObjectName(QStringLiteral("actionCalculate_Stats"));
        centralWidget = new QWidget(MainMenuGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy1);
        checkBox->setMaximumSize(QSize(1000, 1000));

        gridLayout->addWidget(checkBox, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_3->addWidget(label_8);

        componentSelect = new QListWidget(centralWidget);
        componentSelect->setObjectName(QStringLiteral("componentSelect"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(componentSelect->sizePolicy().hasHeightForWidth());
        componentSelect->setSizePolicy(sizePolicy2);
        componentSelect->setMaximumSize(QSize(200, 16777215));

        verticalLayout_3->addWidget(componentSelect);


        horizontalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        Refresh = new QPushButton(centralWidget);
        Refresh->setObjectName(QStringLiteral("Refresh"));

        verticalLayout_4->addWidget(Refresh);

        disjava = new QListWidget(centralWidget);
        disjava->setObjectName(QStringLiteral("disjava"));
        disjava->setProperty("isWrapping", QVariant(false));

        verticalLayout_4->addWidget(disjava);


        horizontalLayout_8->addLayout(verticalLayout_4);


        horizontalLayout_9->addLayout(horizontalLayout_8);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy3);
        label_10->setMaximumSize(QSize(39, 16777215));

        verticalLayout_2->addWidget(label_10);

        disrubric = new QListWidget(centralWidget);
        disrubric->setObjectName(QStringLiteral("disrubric"));
        sizePolicy2.setHeightForWidth(disrubric->sizePolicy().hasHeightForWidth());
        disrubric->setSizePolicy(sizePolicy2);
        disrubric->setMaximumSize(QSize(200, 16777215));
        disrubric->setProperty("isWrapping", QVariant(false));
        disrubric->setLayoutMode(QListView::Batched);

        verticalLayout_2->addWidget(disrubric);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);
        label_11->setMaximumSize(QSize(59, 16777215));

        verticalLayout_2->addWidget(label_11);

        discomment = new QListWidget(centralWidget);
        discomment->setObjectName(QStringLiteral("discomment"));
        sizePolicy2.setHeightForWidth(discomment->sizePolicy().hasHeightForWidth());
        discomment->setSizePolicy(sizePolicy2);
        discomment->setMaximumSize(QSize(200, 16777215));
        discomment->setProperty("isWrapping", QVariant(true));

        verticalLayout_2->addWidget(discomment);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_7->addWidget(label_9);

        displayLabGrade = new QLineEdit(centralWidget);
        displayLabGrade->setObjectName(QStringLiteral("displayLabGrade"));
        sizePolicy1.setHeightForWidth(displayLabGrade->sizePolicy().hasHeightForWidth());
        displayLabGrade->setSizePolicy(sizePolicy1);
        displayLabGrade->setReadOnly(true);

        horizontalLayout_7->addWidget(displayLabGrade);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_9->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_9, 0, 1, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setMaximumSize(QSize(1000, 1000));

        horizontalLayout_6->addWidget(label_2);

        yearSelect = new QComboBox(centralWidget);
        yearSelect->setObjectName(QStringLiteral("yearSelect"));
        sizePolicy1.setHeightForWidth(yearSelect->sizePolicy().hasHeightForWidth());
        yearSelect->setSizePolicy(sizePolicy1);
        yearSelect->setMaximumSize(QSize(1000, 1000));

        horizontalLayout_6->addWidget(yearSelect);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setMaximumSize(QSize(1000, 1000));

        horizontalLayout_5->addWidget(label_3);

        semesterSelect = new QComboBox(centralWidget);
        semesterSelect->setObjectName(QStringLiteral("semesterSelect"));
        sizePolicy1.setHeightForWidth(semesterSelect->sizePolicy().hasHeightForWidth());
        semesterSelect->setSizePolicy(sizePolicy1);
        semesterSelect->setMaximumSize(QSize(1000, 1000));

        horizontalLayout_5->addWidget(semesterSelect);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setMaximumSize(QSize(1000, 1000));

        horizontalLayout_4->addWidget(label_4);

        classSelect = new QComboBox(centralWidget);
        classSelect->setObjectName(QStringLiteral("classSelect"));
        sizePolicy1.setHeightForWidth(classSelect->sizePolicy().hasHeightForWidth());
        classSelect->setSizePolicy(sizePolicy1);
        classSelect->setMaximumSize(QSize(1000, 1000));

        horizontalLayout_4->addWidget(classSelect);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        label_5->setMaximumSize(QSize(1000, 1000));

        horizontalLayout_3->addWidget(label_5);

        sectionSelect = new QComboBox(centralWidget);
        sectionSelect->setObjectName(QStringLiteral("sectionSelect"));
        sizePolicy1.setHeightForWidth(sectionSelect->sizePolicy().hasHeightForWidth());
        sectionSelect->setSizePolicy(sizePolicy1);
        sectionSelect->setMaximumSize(QSize(1000, 1000));

        horizontalLayout_3->addWidget(sectionSelect);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);
        label_6->setMaximumSize(QSize(1000, 1000));

        horizontalLayout_2->addWidget(label_6);

        studentSelect = new QComboBox(centralWidget);
        studentSelect->setObjectName(QStringLiteral("studentSelect"));
        sizePolicy1.setHeightForWidth(studentSelect->sizePolicy().hasHeightForWidth());
        studentSelect->setSizePolicy(sizePolicy1);
        studentSelect->setMaximumSize(QSize(1000, 1000));

        horizontalLayout_2->addWidget(studentSelect);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        label_7->setMaximumSize(QSize(1000, 1000));

        horizontalLayout->addWidget(label_7);

        labSelect = new QComboBox(centralWidget);
        labSelect->setObjectName(QStringLiteral("labSelect"));
        sizePolicy1.setHeightForWidth(labSelect->sizePolicy().hasHeightForWidth());
        labSelect->setSizePolicy(sizePolicy1);
        labSelect->setMaximumSize(QSize(1000, 1000));

        horizontalLayout->addWidget(labSelect);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        saveAndExit = new QPushButton(centralWidget);
        saveAndExit->setObjectName(QStringLiteral("saveAndExit"));

        gridLayout->addWidget(saveAndExit, 2, 0, 1, 1);

        deleteComment = new QPushButton(centralWidget);
        deleteComment->setObjectName(QStringLiteral("deleteComment"));

        gridLayout->addWidget(deleteComment, 2, 1, 1, 1);

        MainMenuGUI->setCentralWidget(centralWidget);
        disrubric->raise();
        disjava->raise();
        discomment->raise();
        componentSelect->raise();
        checkBox->raise();
        Refresh->raise();
        label_8->raise();
        saveAndExit->raise();
        label_10->raise();
        label_11->raise();
        deleteComment->raise();
        menuBar = new QMenuBar(MainMenuGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1283, 19));
        menuBar->setNativeMenuBar(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainMenuGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainMenuGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainMenuGUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainMenuGUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainMenuGUI->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionAdd_New_Labs);
        menuFile->addAction(actionComment);
        menuFile->addAction(actionExport_Lab);
        menuFile->addAction(actionAdd_Rubric);
        menuFile->addAction(actionCalculate_Stats);

        retranslateUi(MainMenuGUI);

        QMetaObject::connectSlotsByName(MainMenuGUI);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenuGUI)
    {
        MainMenuGUI->setWindowTitle(QApplication::translate("MainMenuGUI", "MainMenuGUI", Q_NULLPTR));
        actionAdd_New_Labs->setText(QApplication::translate("MainMenuGUI", "Add New Labs", Q_NULLPTR));
        actionComment->setText(QApplication::translate("MainMenuGUI", "Comment", Q_NULLPTR));
        actionExport_Lab->setText(QApplication::translate("MainMenuGUI", "Export Lab", Q_NULLPTR));
        actionAdd_Rubric->setText(QApplication::translate("MainMenuGUI", "Add Rubric", Q_NULLPTR));
        actionCalculate_Stats->setText(QApplication::translate("MainMenuGUI", "Calculate Stats", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainMenuGUI", "Toggle Anonymous Grading", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainMenuGUI", "Component", Q_NULLPTR));
        Refresh->setText(QApplication::translate("MainMenuGUI", "Refresh", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainMenuGUI", "Rubric", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainMenuGUI", "Comment", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainMenuGUI", "Lab Grade:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainMenuGUI", "Year:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainMenuGUI", "Semester:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainMenuGUI", "Class:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainMenuGUI", "Section:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainMenuGUI", "Student:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainMenuGUI", "Lab Number:", Q_NULLPTR));
        saveAndExit->setText(QApplication::translate("MainMenuGUI", "Save and Exit", Q_NULLPTR));
        deleteComment->setText(QApplication::translate("MainMenuGUI", "Delete Comment", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainMenuGUI", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainMenuGUI: public Ui_MainMenuGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUGUI_H
