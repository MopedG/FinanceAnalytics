#include "validator.h"
#include "Time/time.h"
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
    if (year != Time::getYear())
        success = false;
    if (year == Time::getYear()-1 && month == "Dezember" && Time::getMonth() == 1) //Entry for december last year allowed made in january
        success = true;
    if(year == Time::getYear()+1 && month == "Januar" && Time::getMonth() == 12) //Entry for january next year allowed made in december
        success = true;

    return success;
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
