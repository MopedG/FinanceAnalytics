#include "reader.h"
#include "repository/writer/writer.h"
#include <filesystem>
#include <QIODevice>
#include <QTextStream>
#include <QFile>

std::map<int, std::shared_ptr<EntryData>> Reader::readData()
{
    std::filesystem::path repoPath = Writer::getRepositoryFilePath();
    QFile repoFile(repoPath);
    QString dataLine;
    std::map<int, std::shared_ptr<EntryData>> entryData;
    int id = 0;

    if(repoFile.open(QIODevice::ReadOnly) | QIODevice::Text)
    {
        QTextStream stream(&repoFile);
        while(!stream.atEnd())
        {
            id++;
            dataLine = stream.readLine().trimmed();
            QStringList data = deserealizeData(dataLine);

            QString month = data[0];
            int year = data[1].toInt();
            QString category = data[2];
            double amount = data[3].toDouble();

            std::shared_ptr<EntryData> entry = std::make_shared<EntryData>(std::pair(month, year), category, amount);
            entryData.emplace(std::pair(id, entry));
        }
    }
    return entryData;
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
