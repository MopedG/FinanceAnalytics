#include "mainwindow.h"
#include "addEntry/addEntryWindow/addentrywindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    entryWindow(new AddEntryWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(entryWindow.get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newEntryButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



