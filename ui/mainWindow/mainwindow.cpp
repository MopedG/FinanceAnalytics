#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Repository/repository.h"
#include "repository/datahandler/datahandler.h"
#include "EntryWindow/EntryWindow/addentrywindow.h"
#include "StatisticsWindow/MainWindow/statisticswindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
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

void MainWindow::init()
{
    initRepository();
    initStatisticsWindow();
    initEntryWindow();
}

void MainWindow::on_backToMain()
{
    ui->stackedWidget->setCurrentIndex(0);
    entryWindow.reset();
}

void MainWindow::initEntryWindow()
{
    entryWindow = std::make_unique<AddEntryWindow>(nullptr, repository->entryData);
    ui->stackedWidget->addWidget(entryWindow.get());
    MainWindow::connect(entryWindow.get(), &AddEntryWindow::backToMain, this, &MainWindow::on_backToMain);
}

void MainWindow::initStatisticsWindow()
{
    statisticsWindow = std::make_unique<StatisticsWindow>(nullptr, repository->entryData); //data
    MainWindow::connect(statisticsWindow.get(), &StatisticsWindow::backToMain, this, &MainWindow::on_backToMain);
    ui->stackedWidget->addWidget(statisticsWindow.get());
}

void MainWindow::initRepository()
{
    repository = std::make_unique<Repository>(Datahandler::getEntrysFromFile());
}

