#include "repository.h"
#include "repository/datahandler/datahandler.h"

void Repository::fetchData()
{
    entryData = Datahandler::getEntrysFromFile();
}
