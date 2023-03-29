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

private:
    Ui::MainWindow *ui;
    std::unique_ptr<AddEntryWindow> entryWindow;
};


