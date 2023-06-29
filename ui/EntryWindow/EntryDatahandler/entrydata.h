#pragma once

#include <QObject>

class EntryData
{
public:
    EntryData() = default;
    EntryData(std::pair<QString, int> monthYear, QString category, double amount, QString dateChanged = "");

private:
    std::pair<QString, int> monthYear;
    QString category;
    double amount;
    QString dateChanged;

public:
    void setMonthYear(const std::pair<QString, int> &newMonthYear);
    void setCategory(const QString &newCategory);
    void setAmount(double newAmount);
    void setDateChanged(const QString &newDateChanged);

    std::pair<QString, int> getMonthYear() const;
    QString getCategory() const;
    QString getDateChanged() const;
    double getAmount() const;
    int monthToInt(const QString &month) const;
};

