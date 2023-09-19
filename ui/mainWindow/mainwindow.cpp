#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Repository/repository.h"
#include "repository/datahandler/datahandler.h"
#include "EntryWindow/EntryWindow/addentrywindow.h"
#include "StatisticsWindow/MainWindow/statisticswindow.h"
#include <QMessageBox>
#include <QScreen>
#include <QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setInitialStyles();
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInitialStyles()
{
    setWindowTitle("Finance Tracker");
    QGraphicsDropShadowEffect *headerEffect = new QGraphicsDropShadowEffect( ); //Button Box-Shadow
    QGraphicsDropShadowEffect *newEntryButtonEffect = new QGraphicsDropShadowEffect( );
    QGraphicsDropShadowEffect *statisticsButtonEffect = new QGraphicsDropShadowEffect( );
    headerEffect->setColor(QColor(125, 23, 227, 128));
    headerEffect->setOffset(6);
    headerEffect->setBlurRadius(10);
    newEntryButtonEffect->setColor(QColor(145, 70, 219,128));
    newEntryButtonEffect->setOffset(4);
    newEntryButtonEffect->setBlurRadius(8);

    statisticsButtonEffect->setColor(QColor(255,255,255,128));
    statisticsButtonEffect->setOffset(4);
    statisticsButtonEffect->setBlurRadius(8);
    ui->newEntryButton->setGraphicsEffect(newEntryButtonEffect);
    ui->frame_4->setGraphicsEffect(headerEffect);
    ui->showStatisticsButton->setGraphicsEffect(statisticsButtonEffect);
}

void MainWindow::on_newEntryButton_clicked()
{
    if(entryWindow == nullptr)
        initEntryWindow();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_showStatisticsButton_clicked()
{
    if(reloadStatisticsWindow)
    {
        repository->updateData(Datahandler::getEntrysFromFile());
        statisticsWindow->update(repository->entryData);
    }
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_filePathError()
{
    ui->showStatisticsButton->setDisabled(true);
    QMessageBox::critical(this, tr("Error"), tr("The repository file could not be created/opened. Statistics disabled. "
                                                "Please check if the folder in Username/AppData/Local/FinanceAnalytics exists "
                                                "and has writing permissions or contact the publisher."));
}

void MainWindow::init()
{
    setWindowSizes();
    initRepository();
    initStatisticsWindow();
    initEntryWindow();
}

void MainWindow::on_backToMain(bool newDataAdded)
{
    reloadStatisticsWindow = newDataAdded;
    ui->stackedWidget->setCurrentIndex(0);
    entryWindow.reset();
}

void MainWindow::initEntryWindow()
{
    entryWindow = std::make_unique<AddEntryWindow>(nullptr, repository->entryData);
    ui->stackedWidget->addWidget(entryWindow.get());
    MainWindow::connect(entryWindow.get(), &AddEntryWindow::backToMain, this, &MainWindow::on_backToMain);
    MainWindow::connect(entryWindow.get(), &AddEntryWindow::filePathError, this, &MainWindow::on_filePathError);
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

void MainWindow::setWindowSizes()
{
    setWindowState(Qt::WindowMaximized);
    const QRect screenGeometry = QGuiApplication::screenAt(QCursor::pos())->geometry();
    resize(screenGeometry.width() / 2, screenGeometry.height() / 2);
}

