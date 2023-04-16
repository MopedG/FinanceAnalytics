#pragma once
#include "EntryWindow/EntryDatahandler/entrydata.h"

#include <filesystem>
#include <QObject>

class Writer : public QObject
{
    Q_OBJECT;
public:
    Writer() = default;

    static QStringList serealizeData(const std::vector<std::shared_ptr<EntryData>> &entryData);
    static bool writeData(const QStringList &serealizedData);

    static std::filesystem::path getRepositoryFilePath();

private:
    static std::filesystem::path getAppDataLocalPath();
};


