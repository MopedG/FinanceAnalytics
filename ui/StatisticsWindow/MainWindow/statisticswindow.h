#pragma once

#include <QWidget>

class MonthCard;
class SpendingForm;
class EntryData;

namespace Ui {
class StatisticsWindow;
}

class StatisticsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsWindow(QWidget *parent = nullptr, const std::vector<std::shared_ptr<EntryData>> &data
                              = std::vector<std::shared_ptr<EntryData>>());
    ~StatisticsWindow();

signals:
    void backToMain();


private slots:
    void on_homeButton_clicked();
    void on_monthCardActivated(MonthCard *activeMonthCard);

private:
    Ui::StatisticsWindow *ui;

    MonthCard *monthCard;
    MonthCard *monthCardActive = nullptr;
    SpendingForm *spendingForm;

    void initObjects(const std::vector<std::shared_ptr<EntryData>> &data);
    void initMonthCards(const QStringList &dates);
};


