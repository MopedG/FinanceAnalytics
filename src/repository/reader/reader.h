#pragma once

#include <QObject>

class EntryData;
class Reader
{
public:
    Reader() = default;

    static std::vector<std::shared_ptr<EntryData>> readData();
    static QString getValueAfterComma(QString value, int afterComma);

private:
    static QStringList deserealizeData(const QString &dataLine);

};


