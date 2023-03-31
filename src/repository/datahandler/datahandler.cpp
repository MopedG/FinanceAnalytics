#include "datahandler.h"
#include "sorter/sorter.h"
#include "repository/writer/writer.h"
#include "repository/reader/reader.h"

void Datahandler::saveEntrysToFile(const std::map<int, std::shared_ptr<EntryData> > &entryData)
{
    std::vector<std::shared_ptr<EntryData>> sortedEntrys = Sorter::sortByDate(entryData);
    QStringList serealizedData = Writer::serealizeData(sortedEntrys);
    Writer::writeData(serealizedData);
}

std::map<int, std::shared_ptr<EntryData> > Datahandler::getEntrysFromFile()
{
    return Reader::readData();
}
