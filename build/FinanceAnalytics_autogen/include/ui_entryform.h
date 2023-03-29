/********************************************************************************
** Form generated from reading UI file 'entryform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTRYFORM_H
#define UI_ENTRYFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EntryForm
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *categoryLineEdit;
    QLineEdit *spendingLineEdit;
    QPushButton *editButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelButton;
    QPushButton *submitButton;

    void setupUi(QWidget *EntryForm)
    {
        if (EntryForm->objectName().isEmpty())
            EntryForm->setObjectName("EntryForm");
        EntryForm->resize(1300, 80);
        EntryForm->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 26, 26);"));
        horizontalLayout = new QHBoxLayout(EntryForm);
        horizontalLayout->setObjectName("horizontalLayout");
        categoryLineEdit = new QLineEdit(EntryForm);
        categoryLineEdit->setObjectName("categoryLineEdit");
        categoryLineEdit->setMinimumSize(QSize(200, 50));
        categoryLineEdit->setMaximumSize(QSize(580, 16777215));
        categoryLineEdit->setMouseTracking(true);
        categoryLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"border-radius: 7px;\n"
"color: rgb(255, 255, 255);\n"
"font: 400 14pt \"Segoe UI\";\n"
"qproperty-alignment: AlignCenter;"));

        horizontalLayout->addWidget(categoryLineEdit);

        spendingLineEdit = new QLineEdit(EntryForm);
        spendingLineEdit->setObjectName("spendingLineEdit");
        spendingLineEdit->setMinimumSize(QSize(300, 50));
        spendingLineEdit->setMaximumSize(QSize(300, 50));
        spendingLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color: rgb(74, 74, 74);\n"
"border-radius: 7px;\n"
"qproperty-alignment: AlignCenter;\n"
"color: rgb(229, 229, 229);\n"
"font: 600 14pt \"Segoe UI\";\n"
"}\n"
""));

        horizontalLayout->addWidget(spendingLineEdit);

        editButton = new QPushButton(EntryForm);
        editButton->setObjectName("editButton");
        editButton->setMaximumSize(QSize(50, 50));
        editButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(74, 74, 74);\n"
"border-radius: 25px;\n"
"}\n"
"QPushButton:hover {\n"
"	\n"
"	background-color: rgb(63, 63, 63);\n"
"}\n"
"QPushButton:pressed {\n"
"	\n"
"	background-color: rgb(48, 48, 48);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon);
        editButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(editButton);

        horizontalSpacer_2 = new QSpacerItem(110, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cancelButton = new QPushButton(EntryForm);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setMinimumSize(QSize(50, 50));
        cancelButton->setMaximumSize(QSize(50, 50));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(74, 74, 74);\n"
"border-radius: 9px;\n"
"font-size: 25px;\n"
"}\n"
"QPushButton:hover {\n"
"	\n"
"	background-color: rgb(63, 63, 63);\n"
"}\n"
"QPushButton:pressed {\n"
"	\n"
"	background-color: rgb(48, 48, 48);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/recycle-bin.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon1);
        cancelButton->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(cancelButton);

        submitButton = new QPushButton(EntryForm);
        submitButton->setObjectName("submitButton");
        submitButton->setMinimumSize(QSize(50, 50));
        submitButton->setMaximumSize(QSize(50, 50));
        submitButton->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color: rgb(74, 74, 74);\n"
"	border-radius: 9px;\n"
"	font-size: 25px;\n"
"	color: rgb(85, 255, 0);\n"
"}\n"
"QPushButton:hover {\n"
"	\n"
"	background-color: rgb(63, 63, 63);\n"
"}\n"
"QPushButton:pressed {\n"
"	\n"
"	background-color: rgb(48, 48, 48);\n"
"}\n"
"QPushButton:disabled{\n"
"	\n"
"	//background-color: rgb(148, 148, 148);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        submitButton->setIcon(icon2);
        submitButton->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(submitButton);


        retranslateUi(EntryForm);

        QMetaObject::connectSlotsByName(EntryForm);
    } // setupUi

    void retranslateUi(QWidget *EntryForm)
    {
        EntryForm->setWindowTitle(QCoreApplication::translate("EntryForm", "Form", nullptr));
        categoryLineEdit->setPlaceholderText(QCoreApplication::translate("EntryForm", "Ausgabe 1", nullptr));
        spendingLineEdit->setPlaceholderText(QCoreApplication::translate("EntryForm", "Betrag", nullptr));
        editButton->setText(QString());
        cancelButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EntryForm: public Ui_EntryForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRYFORM_H
