#include "datahandler.h"
#include "sorter/sorter.h"
#include "repository/writer/writer.h"
#include "repository/reader/reader.h"
#include "repository/refactorer/refactorer.h"

bool Datahandler::saveEntrysToFile(const std::map<int, std::shared_ptr<EntryData>> &entryData)
{
    std::vector<std::shared_ptr<EntryData>> fetchedFromFile = getEntrysFromFile();
    for (const auto& entry : entryData)
    {
        if(entry.second->getAmount() != 0)
            fetchedFromFile.emplace_back(entry.second);
    }

    fetchedFromFile = Refactorer::combineEntriesByCategory(fetchedFromFile);

    std::vector<std::shared_ptr<EntryData>> sortedEntrys = Sorter::sortByDate(fetchedFromFile);
    QStringList serealizedData = Writer::serealizeData(sortedEntrys);
    return Writer::writeData(serealizedData);
}

std::vector<std::shared_ptr<EntryData> > Datahandler::getEntrysFromFile()
{
    return Reader::readData();
}
