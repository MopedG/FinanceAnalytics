#pragma once

#include <QMainWindow>

class StatisticsWindow;
class AddEntryWindow;
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
    void on_backToMain();


    void on_showStatisticsButton_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<AddEntryWindow> entryWindow;
    std::unique_ptr<StatisticsWindow> statisticsWindow;

    void initEntryWindow();
    void initStatisticsWindow();
};


