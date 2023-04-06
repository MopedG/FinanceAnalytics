#pragma once

#include <QObject>

class EntryData;
class Reader
{
public:
    Reader() = default;

    static std::vector<std::shared_ptr<EntryData>> readData();

private:
    static QStringList deserealizeData(const QString &dataLine);

};


