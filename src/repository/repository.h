#pragma once
#include <filesystem>
#include <vector>
#include <memory>

class EntryData;
class Repository
{
public:
    Repository(const std::vector<std::shared_ptr<EntryData> > &entryData);
    void updateData(const std::vector<std::shared_ptr<EntryData> > &updatedData);

    std::vector<std::shared_ptr<EntryData>> entryData;

    static std::filesystem::path getAppDataLocalPath();
    static std::filesystem::path getRepositoryFilePath();
};
