#include "repository.h"
#include "qstandardpaths.h"


Repository::Repository(const std::vector<std::shared_ptr<EntryData>> &entryData) : entryData(entryData) {}

void Repository::updateData(const std::vector<std::shared_ptr<EntryData>> &updatedData)
{
    entryData = updatedData;
}

std::filesystem::__cxx11::path Repository::getAppDataLocalPath()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    return path.toStdString();
}

std::filesystem::__cxx11::path Repository::getRepositoryFilePath()
{
    std::filesystem::path folderPath = getAppDataLocalPath() / "Repository";
    std::filesystem::create_directories(folderPath);
    std::filesystem::path fullPath = folderPath / "Repository.txt";
    return fullPath;
}


