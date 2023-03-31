#pragma once
#include <QObject>

class Validator
{
public:
    Validator() = default;

    static bool checkEntry(const QString &category, double amount);
    static bool checkDate(const QString &month, int year);
};

