#pragma once

#include <QObject>

class EntryData
{
public:
    EntryData() = default;
    EntryData(std::pair<QString, int> monthYear, QString category, double amount);

private:
    std::pair<QString, int> monthYear;
    QString category;
    double amount;

public:
    void setMonthYear(const std::pair<QString, int> &newMonthYear);
    void setCategory(const QString &newCategory);
    void setAmount(double newAmount);

    std::pair<QString, int> getMonthYear() const;
    QString getCategory() const;
    double getAmount() const;
    int monthToInt(const QString &month) const;
};

