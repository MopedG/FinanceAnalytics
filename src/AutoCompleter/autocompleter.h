#pragma once
#include <QString>
#include <QStringList>

class AutoCompleter
{
public:
    AutoCompleter(const QStringList &categoryWhiteList);
    QString getAutoCompletion(const QString &userInput);

private:

    QStringList categoryWhiteList;

    bool contains(QString str1, QString str2);
};

