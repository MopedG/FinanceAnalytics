#include "writer.h"
#include <windows.h>
#include <filesystem>
#include <QFile>
#include <QTextStream>

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

void Writer::writeData(const QStringList &serealizedData)
{
    std::filesystem::path filePath = getRepositoryFilePath();
    QFile targetFile(filePath);
    if(targetFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream file(&targetFile);
        for(const auto &entry : serealizedData)
        {
            file << entry << "\n";
        }
    }
}

std::filesystem::path Writer::getRepositoryFilePath()
{
    std::filesystem::path relPath = "src\\repository\\repository.txt";

    HMODULE hModule = GetModuleHandle(NULL);
    TCHAR path[MAX_PATH];
    GetModuleFileName(hModule, path, MAX_PATH);
    std::filesystem::path exePath = std::filesystem::absolute(std::filesystem::path(path)).parent_path();
    exePath = exePath.parent_path();
    std::filesystem::path fullPath = exePath / relPath;

    return fullPath;
}
