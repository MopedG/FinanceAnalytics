#pragma once

#include <QMainWindow>

class StatisticsWindow;
class AddEntryWindow;
class Repository;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_newEntryButton_clicked();
    void on_backToMain(bool newDataAdded = false);
    void on_showStatisticsButton_clicked();
    void on_filePathError();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<AddEntryWindow> entryWindow;
    std::unique_ptr<StatisticsWindow> statisticsWindow;
    std::unique_ptr<Repository> repository;

    bool reloadStatisticsWindow = false;

    void init();
    void initEntryWindow();
    void initStatisticsWindow();
    void initRepository();
    void setWindowSizes();
};


