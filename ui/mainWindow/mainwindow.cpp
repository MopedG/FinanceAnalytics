#include "mainwindow.h"
#include "EntryWindow/EntryWindow/addentrywindow.h"
#include "StatisticsWindow/MainWindow/statisticswindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initStatisticsWindow();
    initEntryWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newEntryButton_clicked()
{
    if(entryWindow == nullptr)
        initEntryWindow();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_showStatisticsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_backToMain()
{
    ui->stackedWidget->setCurrentIndex(0);
    entryWindow.reset();
}



void MainWindow::initEntryWindow()
{
    entryWindow = std::make_unique<AddEntryWindow>();
    ui->stackedWidget->addWidget(entryWindow.get());
    MainWindow::connect(entryWindow.get(), &AddEntryWindow::backToMain, this, &MainWindow::on_backToMain);
}

void MainWindow::initStatisticsWindow()
{
    statisticsWindow = std::make_unique<StatisticsWindow>();
    MainWindow::connect(statisticsWindow.get(), &StatisticsWindow::backToMain, this, &MainWindow::on_backToMain);
    ui->stackedWidget->addWidget(statisticsWindow.get());
}

