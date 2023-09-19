#pragma once
#include <QString>

class EntryData;
class AutoCompleter
{
public:
    QString getAutoCompletion(const QString &userInput);

private:
    AutoCompleter() = default;
};

