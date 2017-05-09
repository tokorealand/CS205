/********************************************************************************
** Form generated from reading UI file 'statsgui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATSGUI_H
#define UI_STATSGUI_H

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

class Ui_Widget
{
public:
    QLabel *medianLabel;
    QLabel *meanLabel;
    QLabel *minLabel;
    QLabel *maxLabel;
    QLabel *medianDisplay;
    QLabel *meanDisplay;
    QLabel *minDisplay;
    QLabel *maxDisplay;
    QPushButton *calcButton;
    QPushButton *doneButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *yearLabel;
    QComboBox *yearComboBox;
    QLabel *semesterLabel;
    QComboBox *semesterComboBox;
    QLabel *classLabel;
    QComboBox *classComboBox;
    QLabel *sectionLabel;
    QComboBox *sectionComboBox;
    QLabel *LabNoLabel;
    QComboBox *labNoComboBox;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(835, 291);
        medianLabel = new QLabel(Widget);
        medianLabel->setObjectName(QStringLiteral("medianLabel"));
        medianLabel->setGeometry(QRect(200, 90, 59, 14));
        meanLabel = new QLabel(Widget);
        meanLabel->setObjectName(QStringLiteral("meanLabel"));
        meanLabel->setGeometry(QRect(200, 120, 59, 14));
        minLabel = new QLabel(Widget);
        minLabel->setObjectName(QStringLiteral("minLabel"));
        minLabel->setGeometry(QRect(200, 150, 59, 14));
        maxLabel = new QLabel(Widget);
        maxLabel->setObjectName(QStringLiteral("maxLabel"));
        maxLabel->setGeometry(QRect(200, 180, 59, 14));
        medianDisplay = new QLabel(Widget);
        medianDisplay->setObjectName(QStringLiteral("medianDisplay"));
        medianDisplay->setGeometry(QRect(260, 90, 59, 14));
        meanDisplay = new QLabel(Widget);
        meanDisplay->setObjectName(QStringLiteral("meanDisplay"));
        meanDisplay->setGeometry(QRect(260, 120, 59, 20));
        minDisplay = new QLabel(Widget);
        minDisplay->setObjectName(QStringLiteral("minDisplay"));
        minDisplay->setGeometry(QRect(260, 150, 59, 14));
        maxDisplay = new QLabel(Widget);
        maxDisplay->setObjectName(QStringLiteral("maxDisplay"));
        maxDisplay->setGeometry(QRect(260, 180, 59, 14));
        calcButton = new QPushButton(Widget);
        calcButton->setObjectName(QStringLiteral("calcButton"));
        calcButton->setGeometry(QRect(740, 50, 80, 22));
        doneButton = new QPushButton(Widget);
        doneButton->setObjectName(QStringLiteral("doneButton"));
        doneButton->setGeometry(QRect(740, 260, 80, 22));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 811, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        yearLabel = new QLabel(widget);
        yearLabel->setObjectName(QStringLiteral("yearLabel"));

        horizontalLayout->addWidget(yearLabel);

        yearComboBox = new QComboBox(widget);
        yearComboBox->setObjectName(QStringLiteral("yearComboBox"));

        horizontalLayout->addWidget(yearComboBox);

        semesterLabel = new QLabel(widget);
        semesterLabel->setObjectName(QStringLiteral("semesterLabel"));

        horizontalLayout->addWidget(semesterLabel);

        semesterComboBox = new QComboBox(widget);
        semesterComboBox->setObjectName(QStringLiteral("semesterComboBox"));

        horizontalLayout->addWidget(semesterComboBox);

        classLabel = new QLabel(widget);
        classLabel->setObjectName(QStringLiteral("classLabel"));

        horizontalLayout->addWidget(classLabel);

        classComboBox = new QComboBox(widget);
        classComboBox->setObjectName(QStringLiteral("classComboBox"));

        horizontalLayout->addWidget(classComboBox);

        sectionLabel = new QLabel(widget);
        sectionLabel->setObjectName(QStringLiteral("sectionLabel"));

        horizontalLayout->addWidget(sectionLabel);

        sectionComboBox = new QComboBox(widget);
        sectionComboBox->setObjectName(QStringLiteral("sectionComboBox"));

        horizontalLayout->addWidget(sectionComboBox);

        LabNoLabel = new QLabel(widget);
        LabNoLabel->setObjectName(QStringLiteral("LabNoLabel"));

        horizontalLayout->addWidget(LabNoLabel);

        labNoComboBox = new QComboBox(widget);
        labNoComboBox->setObjectName(QStringLiteral("labNoComboBox"));

        horizontalLayout->addWidget(labNoComboBox);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        medianLabel->setText(QApplication::translate("Widget", "median:", Q_NULLPTR));
        meanLabel->setText(QApplication::translate("Widget", "mean:", Q_NULLPTR));
        minLabel->setText(QApplication::translate("Widget", "min:", Q_NULLPTR));
        maxLabel->setText(QApplication::translate("Widget", "max:", Q_NULLPTR));
        medianDisplay->setText(QString());
        meanDisplay->setText(QString());
        minDisplay->setText(QString());
        maxDisplay->setText(QString());
        calcButton->setText(QApplication::translate("Widget", "Calculate", Q_NULLPTR));
        doneButton->setText(QApplication::translate("Widget", "Done", Q_NULLPTR));
        yearLabel->setText(QApplication::translate("Widget", "Year:", Q_NULLPTR));
        semesterLabel->setText(QApplication::translate("Widget", "Semester:", Q_NULLPTR));
        classLabel->setText(QApplication::translate("Widget", "Class:", Q_NULLPTR));
        sectionLabel->setText(QApplication::translate("Widget", "Section:", Q_NULLPTR));
        LabNoLabel->setText(QApplication::translate("Widget", "Lab  Number:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATSGUI_H
