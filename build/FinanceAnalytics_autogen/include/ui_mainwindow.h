/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QPushButton *newEntryButton;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1518, 718);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 26, 26);"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page1 = new QWidget();
        page1->setObjectName("page1");
        page1->setMinimumSize(QSize(1000, 600));
        verticalLayout_2 = new QVBoxLayout(page1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frame = new QFrame(page1);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(800, 200));
        frame->setMaximumSize(QSize(16777215, 100));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        newEntryButton = new QPushButton(frame);
        newEntryButton->setObjectName("newEntryButton");
        newEntryButton->setMinimumSize(QSize(0, 50));
        newEntryButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius: 5px;\n"
"	background-color: rgb(131, 202, 131);\n"
"	color: rgb(26, 29, 27);\n"
"	font: 700 20pt \"Segoe UI\";\n"
"}\n"
"QPushButton:hover {\n"
"	/*color: rgb(230, 230, 230);*/\n"
"	\n"
"	background-color: rgb(114, 176, 114);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(102, 157, 102);\n"
"}"));

        verticalLayout_3->addWidget(newEntryButton);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(0, 50));
        pushButton_4->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	border-radius: 5px;\n"
"	background-color: rgb(245, 245, 245);\n"
"	color: rgb(51, 51, 51);\n"
"	font: 700 20pt \"Segoe UI\";\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(207, 207, 207);\n"
"}\n"
"QPushButton:pressed {\n"
"	\n"
"	background-color: rgb(175, 175, 175);\n"
"}"));

        verticalLayout_3->addWidget(pushButton_4);


        verticalLayout_2->addWidget(frame, 0, Qt::AlignHCenter|Qt::AlignTop);

        stackedWidget->addWidget(page1);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        newEntryButton->setText(QCoreApplication::translate("MainWindow", "Neuen Eintrag anlegen", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Budget anzeigen/bearbeiten", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
