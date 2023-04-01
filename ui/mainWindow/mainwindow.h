#pragma once

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    AddEntryWindow *entryWindow;

    void initEntryWindow();
};


