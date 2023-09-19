#include "autocompleter.h"

AutoCompleter::AutoCompleter(const QStringList &categoryWhiteList) : categoryWhiteList(categoryWhiteList){};

QString AutoCompleter::getAutoCompletion(const QString &input)
{
    for(int i = 0; i < categoryWhiteList.size(); i++)
    {
        if(categoryWhiteList.at(i).startsWith(input) && contains(categoryWhiteList.at(i), input))
        {
            return categoryWhiteList.at(i);
        }
    }
    return input;
}

bool AutoCompleter::contains(QString str1, QString str2)
{
    return (str1.contains(str2));
}
