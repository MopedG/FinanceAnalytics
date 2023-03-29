#include "entrydata.h"


EntryData::EntryData(std::pair<QString, int> monthYear, QString category, double amount) :
    monthYear(monthYear),
    category(category),
    amount(amount)
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

void EntryData::setCategory(const QString &newCategory)
{
    category = newCategory;
}

double EntryData::getAmount() const
{
    return amount;
}

int EntryData::monthToInt(const QString &month) const
{
    if (month == "januar")
            return 1;
        else if (month == "februar")
            return 2;
        else if (month == "märz")
            return 3;
        else if (month == "april")
            return 4;
        else if (month == "mai")
            return 5;
        else if (month == "juni")
            return 6;
        else if (month == "juli")
            return 7;
        else if (month == "august")
            return 8;
        else if (month == "september")
            return 9;
        else if (month == "oktober")
            return 10;
        else if (month == "november")
            return 11;
        else if (month == "dezember")
            return 12;
}

void EntryData::setAmount(double newAmount)
{
    amount = newAmount;
}
