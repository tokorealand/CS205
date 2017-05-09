/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *doneButton;
    QListWidget *commentList;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *rubricSectionLabel;
    QComboBox *rubricSectionDropDown;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *commentTextLabel;
    QLineEdit *commentText;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *pointsOffLabel;
    QDoubleSpinBox *pointsOffSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *colorLabel;
    QComboBox *colorDropDown;
    QLabel *lineNoLabel;
    QLineEdit *lineNo;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        doneButton = new QPushButton(Dialog);
        doneButton->setObjectName(QStringLiteral("doneButton"));
        doneButton->setGeometry(QRect(310, 270, 80, 22));
        commentList = new QListWidget(Dialog);
        commentList->setObjectName(QStringLiteral("commentList"));
        commentList->setGeometry(QRect(10, 130, 381, 131));
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 381, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        rubricSectionLabel = new QLabel(layoutWidget);
        rubricSectionLabel->setObjectName(QStringLiteral("rubricSectionLabel"));

        horizontalLayout_3->addWidget(rubricSectionLabel);

        rubricSectionDropDown = new QComboBox(layoutWidget);
        rubricSectionDropDown->setObjectName(QStringLiteral("rubricSectionDropDown"));

        horizontalLayout_3->addWidget(rubricSectionDropDown);

        layoutWidget1 = new QWidget(Dialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 381, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        commentTextLabel = new QLabel(layoutWidget1);
        commentTextLabel->setObjectName(QStringLiteral("commentTextLabel"));

        horizontalLayout_4->addWidget(commentTextLabel);

        commentText = new QLineEdit(layoutWidget1);
        commentText->setObjectName(QStringLiteral("commentText"));

        horizontalLayout_4->addWidget(commentText);

        layoutWidget2 = new QWidget(Dialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 80, 387, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pointsOffLabel = new QLabel(layoutWidget2);
        pointsOffLabel->setObjectName(QStringLiteral("pointsOffLabel"));

        horizontalLayout->addWidget(pointsOffLabel);

        pointsOffSpinBox = new QDoubleSpinBox(layoutWidget2);
        pointsOffSpinBox->setObjectName(QStringLiteral("pointsOffSpinBox"));

        horizontalLayout->addWidget(pointsOffSpinBox);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        colorLabel = new QLabel(layoutWidget2);
        colorLabel->setObjectName(QStringLiteral("colorLabel"));

        horizontalLayout_2->addWidget(colorLabel);

        colorDropDown = new QComboBox(layoutWidget2);
        colorDropDown->setObjectName(QStringLiteral("colorDropDown"));

        horizontalLayout_2->addWidget(colorDropDown);

        lineNoLabel = new QLabel(layoutWidget2);
        lineNoLabel->setObjectName(QStringLiteral("lineNoLabel"));

        horizontalLayout_2->addWidget(lineNoLabel);

        lineNo = new QLineEdit(layoutWidget2);
        lineNo->setObjectName(QStringLiteral("lineNo"));

        horizontalLayout_2->addWidget(lineNo);


        horizontalLayout_5->addLayout(horizontalLayout_2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        doneButton->setText(QApplication::translate("Dialog", "Done", Q_NULLPTR));
        rubricSectionLabel->setText(QApplication::translate("Dialog", "Rubric Section: ", Q_NULLPTR));
        commentTextLabel->setText(QApplication::translate("Dialog", "Comment Text: ", Q_NULLPTR));
        pointsOffLabel->setText(QApplication::translate("Dialog", "Points off:", Q_NULLPTR));
        colorLabel->setText(QApplication::translate("Dialog", "Highlight?", Q_NULLPTR));
        colorDropDown->clear();
        colorDropDown->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Yes", Q_NULLPTR)
         << QApplication::translate("Dialog", "No", Q_NULLPTR)
        );
        lineNoLabel->setText(QApplication::translate("Dialog", "Line No:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
