/********************************************************************************
** Form generated from reading UI file 'statisticsgui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSGUI_H
#define UI_STATISTICSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsGui
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *yearlabel;
    QComboBox *yearSelect;
    QLabel *semesterlabel;
    QComboBox *semesterSelect;
    QLabel *classLabel;
    QComboBox *classSelect;
    QLabel *sectionlabel;
    QComboBox *sectionSelect;
    QLabel *labnolabel;
    QComboBox *labNoSelect;
    QLabel *meanlabel;
    QLabel *meandisplay;
    QLabel *medianlabel;
    QLabel *mindisplay;
    QPushButton *calcbutton;
    QLabel *maxdisplay;
    QLabel *mediandisplay;
    QPushButton *doneButton;
    QLabel *maxlabel;
    QLabel *minlabel;

    void setupUi(QWidget *StatisticsGui)
    {
        if (StatisticsGui->objectName().isEmpty())
            StatisticsGui->setObjectName(QStringLiteral("StatisticsGui"));
        StatisticsGui->resize(841, 381);
        layoutWidget = new QWidget(StatisticsGui);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 821, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        yearlabel = new QLabel(layoutWidget);
        yearlabel->setObjectName(QStringLiteral("yearlabel"));

        horizontalLayout->addWidget(yearlabel);

        yearSelect = new QComboBox(layoutWidget);
        yearSelect->setObjectName(QStringLiteral("yearSelect"));

        horizontalLayout->addWidget(yearSelect);

        semesterlabel = new QLabel(layoutWidget);
        semesterlabel->setObjectName(QStringLiteral("semesterlabel"));

        horizontalLayout->addWidget(semesterlabel);

        semesterSelect = new QComboBox(layoutWidget);
        semesterSelect->setObjectName(QStringLiteral("semesterSelect"));

        horizontalLayout->addWidget(semesterSelect);

        classLabel = new QLabel(layoutWidget);
        classLabel->setObjectName(QStringLiteral("classLabel"));

        horizontalLayout->addWidget(classLabel);

        classSelect = new QComboBox(layoutWidget);
        classSelect->setObjectName(QStringLiteral("classSelect"));

        horizontalLayout->addWidget(classSelect);

        sectionlabel = new QLabel(layoutWidget);
        sectionlabel->setObjectName(QStringLiteral("sectionlabel"));

        horizontalLayout->addWidget(sectionlabel);

        sectionSelect = new QComboBox(layoutWidget);
        sectionSelect->setObjectName(QStringLiteral("sectionSelect"));

        horizontalLayout->addWidget(sectionSelect);

        labnolabel = new QLabel(layoutWidget);
        labnolabel->setObjectName(QStringLiteral("labnolabel"));

        horizontalLayout->addWidget(labnolabel);

        labNoSelect = new QComboBox(layoutWidget);
        labNoSelect->setObjectName(QStringLiteral("labNoSelect"));

        horizontalLayout->addWidget(labNoSelect);

        meanlabel = new QLabel(StatisticsGui);
        meanlabel->setObjectName(QStringLiteral("meanlabel"));
        meanlabel->setGeometry(QRect(220, 100, 59, 14));
        meandisplay = new QLabel(StatisticsGui);
        meandisplay->setObjectName(QStringLiteral("meandisplay"));
        meandisplay->setGeometry(QRect(280, 100, 59, 14));
        medianlabel = new QLabel(StatisticsGui);
        medianlabel->setObjectName(QStringLiteral("medianlabel"));
        medianlabel->setGeometry(QRect(210, 120, 59, 14));
        mindisplay = new QLabel(StatisticsGui);
        mindisplay->setObjectName(QStringLiteral("mindisplay"));
        mindisplay->setGeometry(QRect(270, 160, 59, 14));
        calcbutton = new QPushButton(StatisticsGui);
        calcbutton->setObjectName(QStringLiteral("calcbutton"));
        calcbutton->setGeometry(QRect(750, 50, 80, 22));
        maxdisplay = new QLabel(StatisticsGui);
        maxdisplay->setObjectName(QStringLiteral("maxdisplay"));
        maxdisplay->setGeometry(QRect(270, 140, 59, 14));
        mediandisplay = new QLabel(StatisticsGui);
        mediandisplay->setObjectName(QStringLiteral("mediandisplay"));
        mediandisplay->setGeometry(QRect(280, 120, 59, 14));
        doneButton = new QPushButton(StatisticsGui);
        doneButton->setObjectName(QStringLiteral("doneButton"));
        doneButton->setGeometry(QRect(710, 350, 80, 22));
        maxlabel = new QLabel(StatisticsGui);
        maxlabel->setObjectName(QStringLiteral("maxlabel"));
        maxlabel->setGeometry(QRect(230, 140, 59, 14));
        minlabel = new QLabel(StatisticsGui);
        minlabel->setObjectName(QStringLiteral("minlabel"));
        minlabel->setGeometry(QRect(230, 160, 59, 14));

        retranslateUi(StatisticsGui);

        QMetaObject::connectSlotsByName(StatisticsGui);
    } // setupUi

    void retranslateUi(QWidget *StatisticsGui)
    {
        StatisticsGui->setWindowTitle(QApplication::translate("StatisticsGui", "StatisticsGui", Q_NULLPTR));
        yearlabel->setText(QApplication::translate("StatisticsGui", "year:", Q_NULLPTR));
        semesterlabel->setText(QApplication::translate("StatisticsGui", "semester", Q_NULLPTR));
        classLabel->setText(QApplication::translate("StatisticsGui", "class ", Q_NULLPTR));
        sectionlabel->setText(QApplication::translate("StatisticsGui", "section", Q_NULLPTR));
        labnolabel->setText(QApplication::translate("StatisticsGui", "lab number", Q_NULLPTR));
        meanlabel->setText(QApplication::translate("StatisticsGui", "mean", Q_NULLPTR));
        meandisplay->setText(QString());
        medianlabel->setText(QApplication::translate("StatisticsGui", "median", Q_NULLPTR));
        mindisplay->setText(QString());
        calcbutton->setText(QApplication::translate("StatisticsGui", "calculate", Q_NULLPTR));
        maxdisplay->setText(QString());
        mediandisplay->setText(QString());
        doneButton->setText(QApplication::translate("StatisticsGui", "done", Q_NULLPTR));
        maxlabel->setText(QApplication::translate("StatisticsGui", "max", Q_NULLPTR));
        minlabel->setText(QApplication::translate("StatisticsGui", "min", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StatisticsGui: public Ui_StatisticsGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSGUI_H
