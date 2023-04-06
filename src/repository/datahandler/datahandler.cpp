#include "datahandler.h"
#include "sorter/sorter.h"
#include "repository/writer/writer.h"
#include "repository/reader/reader.h"

void Datahandler::saveEntrysToFile(const std::map<int, std::shared_ptr<EntryData> > &entryData)
{
    std::vector<std::shared_ptr<EntryData>> fetchedFromFile = getEntrysFromFile();
    for (const auto& entry : entryData)
    {
        fetchedFromFile.push_back(entry.second);
    }
    std::vector<std::shared_ptr<EntryData>> sortedEntrys = Sorter::sortByDate(fetchedFromFile);
    QStringList serealizedData = Writer::serealizeData(sortedEntrys);
    Writer::writeData(serealizedData);
}

std::vector<std::shared_ptr<EntryData> > Datahandler::getEntrysFromFile()
{
    return Reader::readData();
}
