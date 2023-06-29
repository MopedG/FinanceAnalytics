#include "writer.h"
#include "Repository/repository.h"
#include <filesystem>
#include <QFile>
#include <QTextStream>
#include <Windows.h>
#include <QStandardPaths>

QStringList Writer::serealizeData(const std::vector<std::shared_ptr<EntryData>> &entryData)
{
    QStringList serealizedData;
    QString serealized;
    for(const auto &entry : entryData)
    {
        serealized += entry->getMonthYear().first + ",";
        serealized += QString::number(entry->getMonthYear().second) + ",";
        serealized += entry->getCategory() + ",";
        serealized += QString::number(entry->getAmount());
        serealizedData.emplace_back(serealized);
        serealized = "";
    }
    return serealizedData;
}

bool Writer::writeData(const QStringList &serealizedData)
{
    std::filesystem::path filePath = Repository::getRepositoryFilePath();
    QFile targetFile(filePath);
    if(targetFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream file(&targetFile);
        for(const auto &entry : serealizedData)
        {
            file << entry << "\n";
        }
        return true;
    }
    else {
        return false;
    }
}



