#pragma once

#include <vector>
#include <map>
#include <memory>

class EntryData;
class Datahandler
{
public:
    Datahandler() = default;

    static bool saveEntrysToFile(const std::map<int, std::shared_ptr<EntryData>>& entryData);
    static std::vector<std::shared_ptr<EntryData>> getEntrysFromFile();
};


