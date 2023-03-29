/********************************************************************************
** Form generated from reading UI file 'addentrywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDENTRYWINDOW_H
#define UI_ADDENTRYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addEntryWindow
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *monthEdit;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *yearEdit;
    QFrame *entryFrame;
    QWidget *layoutWidget_2;
    QVBoxLayout *cellLayout_2;

    void setupUi(QWidget *addEntryWindow)
    {
        if (addEntryWindow->objectName().isEmpty())
            addEntryWindow->setObjectName("addEntryWindow");
        addEntryWindow->resize(1880, 1020);
        addEntryWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 26, 26);"));
        verticalLayout = new QVBoxLayout(addEntryWindow);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(addEntryWindow);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(1230, 80));
        frame->setMaximumSize(QSize(16777215, 70));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(17, -1, 17, -1);
        monthEdit = new QLineEdit(frame);
        monthEdit->setObjectName("monthEdit");
        monthEdit->setMinimumSize(QSize(300, 50));
        monthEdit->setMaximumSize(QSize(580, 16777215));
        monthEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"border-radius: 7px;\n"
"color: rgb(255, 255, 255);\n"
"font: 700 14pt \"Segoe UI\";\n"
"qproperty-alignment: AlignCenter;"));

        horizontalLayout_2->addWidget(monthEdit);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        yearEdit = new QLineEdit(frame);
        yearEdit->setObjectName("yearEdit");
        yearEdit->setMinimumSize(QSize(290, 50));
        yearEdit->setMaximumSize(QSize(1200, 16777215));
        yearEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(74, 74, 74);\n"
"border-radius: 7px;\n"
"qproperty-alignment: AlignCenter;\n"
"color: rgb(255, 255, 255);\n"
"font: 700 14pt \"Segoe UI\";"));

        horizontalLayout_2->addWidget(yearEdit);


        verticalLayout->addWidget(frame, 0, Qt::AlignHCenter);

        entryFrame = new QFrame(addEntryWindow);
        entryFrame->setObjectName("entryFrame");
        entryFrame->setMinimumSize(QSize(1230, 700));
        entryFrame->setMaximumSize(QSize(16777215, 500));
        entryFrame->setFrameShape(QFrame::StyledPanel);
        entryFrame->setFrameShadow(QFrame::Raised);
        layoutWidget_2 = new QWidget(entryFrame);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 10, 1211, 681));
        cellLayout_2 = new QVBoxLayout(layoutWidget_2);
        cellLayout_2->setSpacing(6);
        cellLayout_2->setObjectName("cellLayout_2");
        cellLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        cellLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(entryFrame, 0, Qt::AlignHCenter|Qt::AlignTop);


        retranslateUi(addEntryWindow);

        QMetaObject::connectSlotsByName(addEntryWindow);
    } // setupUi

    void retranslateUi(QWidget *addEntryWindow)
    {
        addEntryWindow->setWindowTitle(QCoreApplication::translate("addEntryWindow", "Form", nullptr));
        monthEdit->setPlaceholderText(QCoreApplication::translate("addEntryWindow", "Monat", nullptr));
        yearEdit->setPlaceholderText(QCoreApplication::translate("addEntryWindow", "Jahr", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addEntryWindow: public Ui_addEntryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDENTRYWINDOW_H
