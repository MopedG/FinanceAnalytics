#pragma once

#include <map>
#include <memory>

class EntryData;
class Datahandler
{
public:
    Datahandler() = default;

    static void saveEntrysToFile(const std::map<int, std::shared_ptr<EntryData>>& entryData);
    static std::map<int, std::shared_ptr<EntryData>> getEntrysFromFile();
};


