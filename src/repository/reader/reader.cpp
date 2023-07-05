#include "reader.h"
#include "Repository/repository.h"
#include "EntryWindow/EntryDatahandler/entrydata.h"
#include <filesystem>
#include <QIODevice>
#include <QTextStream>
#include <QFile>

std::vector<std::shared_ptr<EntryData>> Reader::readData()
{
    std::filesystem::path repoPath = Repository::getRepositoryFilePath();
    QFile repoFile(repoPath);
    QString dataLine;
    std::vector<std::shared_ptr<EntryData>> entryData;

    if(repoFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&repoFile);
        while(!stream.atEnd())
        {
            dataLine = stream.readLine().trimmed();
            if(dataLine != "")
            {
                QStringList data = deserealizeData(dataLine);

                QString month = data[0];
                int year = data[1].toInt();
                QString category = data[2];
                double amount = data[3].toDouble();
                QString dateChanged = data[4];

                std::shared_ptr<EntryData> entry = std::make_shared<EntryData>(std::pair(month, year), category, amount);
                entry->setDateChanged(dateChanged);
                entryData.emplace_back(entry);
            }
        }
        repoFile.close();
    }
    return entryData;
}

QString Reader::getValueAfterComma(QString value, int afterComma)
{
    QStringList parts = value.split(',');
    if(parts.size() > afterComma)
    {
        return parts[afterComma];
    }
    return QString();
}

QStringList Reader::deserealizeData(const QString &dataLine)
{
    QStringList values;
    QString qDataLine = dataLine;
    QTextStream stream(&qDataLine, QIODevice::Text);

    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        QStringList lineValues = line.split(",");
        for(const QString &value : lineValues)
        {
            values.emplace_back(value);
        }
    }

    return values;
}
