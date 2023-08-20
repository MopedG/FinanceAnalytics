#include "entrydata.h"


EntryData::EntryData(std::pair<QString, int> monthYear, QString category, double amount, QString dateChanged) :
    monthYear(monthYear),
    category(category),
    amount(amount),
    dateChanged(dateChanged)
{}

std::pair<QString, int> EntryData::getMonthYear() const
{
    return monthYear;
}

void EntryData::setMonthYear(const std::pair<QString, int> &newMonthYear)
{
    monthYear = newMonthYear;
}

QString EntryData::getCategory() const
{
    return category;
}

QString EntryData::getDateChanged() const
{
    return dateChanged;
}

void EntryData::setCategory(const QString &newCategory)
{
    category = newCategory;
}

double EntryData::getAmount() const
{
    return amount;
}

QString EntryData::getKey() const
{
    QString key;
    key = category + getMonthYear().first + QString::number(getMonthYear().second);
    return key;
}

int EntryData::monthToInt(const QString &month) const
{
    if (month == "Januar")
            return 1;
        else if (month == "Februar")
            return 2;
        else if (month == "März")
            return 3;
        else if (month == "April")
            return 4;
        else if (month == "Mai")
            return 5;
        else if (month == "Juni")
            return 6;
        else if (month == "Juli")
            return 7;
        else if (month == "August")
            return 8;
        else if (month == "September")
            return 9;
        else if (month == "Oktober")
            return 10;
        else if (month == "November")
            return 11;
        else if (month == "Dezember")
            return 12;
}

void EntryData::setAmount(double newAmount)
{
    amount = newAmount;
}

void EntryData::setDateChanged(const QString &newDateChanged)
{
    dateChanged = newDateChanged;
}
