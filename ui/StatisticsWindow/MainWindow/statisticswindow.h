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


    void update(const std::vector<std::shared_ptr<EntryData>> &data);

signals:
    void backToMain(bool newDataAdded = false);


private slots:
    void on_homeButton_clicked();
    void on_monthCardActivated(MonthCard *activeMonthCard);

private:
    Ui::StatisticsWindow *ui;

    MonthCard *monthCard;
    MonthCard *monthCardActive = nullptr;
    QString lastActiveMonthCard;
    SpendingForm *spendingForm;

    std::vector<std::shared_ptr<EntryData>> data;

    void initObjects(const std::vector<std::shared_ptr<EntryData>> &data);
    void updateMonthCard(const QStringList &dates);
    void updateSpendingForms(const std::vector<std::pair<QString, double>> &spendings);
    void createMonthCards(const QStringList &dates, bool update = false);
    void createSpendingForms(const std::vector<std::pair<QString, double>> &spendings);
    void createDonutChart(const std::vector<std::pair<QString, double> > &spendings);
    void removeMonthCards();
    void removeSpendingForms();
};


