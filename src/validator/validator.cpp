#include "validator.h"
#include <chrono>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

bool Validator::checkEntry(const QString &category, double amount)
{
    QRegularExpression re("\\d+");
    QRegularExpressionMatch match = re.match(category);

    if(match.hasMatch() || category == "")
    {
        return false;
    }
    if(amount == 0)
    {
        return false;
    }
    return true;
}

bool Validator::checkDate(const QString &month, int year)
{
    std::vector<QString> validMonths {"Januar", "Februar", "März", "April", "Mai", "Juni",
                                      "Juli", "August", "September", "Oktober", "November", "Dezember"};
    auto it = std::find(validMonths.begin(), validMonths.end(), month);
    if(it == validMonths.end())
        return false;

    bool success = true;
    if (year != getCurrentYear())
        success = false;
    if (year == getCurrentYear()-1 && month == "Dezember" && getCurrentMonth() == 1) //Entry for december last year allowed made in january
        success = true;
    if(year == getCurrentYear()+1 && month == "Januar" && getCurrentMonth() == 12) //Entry for january next year allowed made in december
        success = true;

    return success;
}

int Validator::getCurrentYear()
{
    auto currentTime  = std::chrono::system_clock::now();
    std::time_t timeT  = std::chrono::system_clock::to_time_t(currentTime);
    std::tm localTime = *std::localtime(&timeT);
    int year = localTime.tm_year + 1900;
    return year;
}

int Validator::getCurrentMonth()
{
    auto currentTime  = std::chrono::system_clock::now();
    std::time_t timeT  = std::chrono::system_clock::to_time_t(currentTime);
    std::tm localTime = *std::localtime(&timeT);
    int month = localTime.tm_mon + 1;
    return 12;
}

bool Validator::categoryInWhiteList(const QStringList &whiteList, const QString &category)
{
    bool inWhiteList = false;

    for(const auto &entry : whiteList)
    {
        if(entry == category)
        {
            inWhiteList = true;
            break;
        }
    }
    return inWhiteList;
}
