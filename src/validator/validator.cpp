#include "validator.h"
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
    std::vector<QString> validMonths {"januar", "februar", "märz", "april", "mai", "juni",
                                      "juli", "august", "september", "oktober", "november", "dezember"};
    auto it = std::find(validMonths.begin(), validMonths.end(), month.toLower());
    if(it == validMonths.end())
        return false;
    if(year != 2023)
        return false;

    return true;
}
