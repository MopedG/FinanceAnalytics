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
    if(year != getCurrentYear())
        return false;

    return true;
}

int Validator::getCurrentYear()
{
    auto currentTime  = std::chrono::system_clock::now();
    std::time_t timeT  = std::chrono::system_clock::to_time_t(currentTime);
    std::tm localTime = *std::localtime(&timeT);
    int year = localTime.tm_year + 1900;
    return year;
}
