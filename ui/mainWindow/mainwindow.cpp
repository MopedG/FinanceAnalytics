#include "mainwindow.h"
#include "EntryWindow/EntryWindow/addentrywindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    entryWindow = new AddEntryWindow();
    ui->stackedWidget->addWidget(entryWindow);
    MainWindow::connect(entryWindow, &AddEntryWindow::backToMain, this, &MainWindow::on_backToMain);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newEntryButton_clicked()
{
    if(entryWindow == nullptr)
        initEntryWindow();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_backToMain()
{
    ui->stackedWidget->setCurrentIndex(0);
    entryWindow->close();
}

void MainWindow::initEntryWindow()
{
    entryWindow = new AddEntryWindow();
    ui->stackedWidget->addWidget(entryWindow);
    MainWindow::connect(entryWindow, &AddEntryWindow::backToMain, this, &MainWindow::on_backToMain);
}



