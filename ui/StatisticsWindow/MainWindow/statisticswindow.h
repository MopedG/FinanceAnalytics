#pragma once

#include <QWidget>

class MonthCard;
class SpendingForm;


namespace Ui {
class StatisticsWindow;
}

class StatisticsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsWindow(QWidget *parent = nullptr);
    ~StatisticsWindow();

signals:
    void backToMain();

private slots:
    void on_homeButton_clicked();

private:
    Ui::StatisticsWindow *ui;

    MonthCard *monthCard;
    SpendingForm *spendingForm;

    void initObjects();
};


