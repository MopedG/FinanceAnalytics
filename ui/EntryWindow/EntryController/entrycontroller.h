#pragma once

#include "EntryWindow/EntryDatahandler/entrydatahandler.h"

#include <QObject>

class EntryController : public QObject
{
    Q_OBJECT

public:
    EntryController(QStringList categoryWhiteList);
    ~EntryController() = default;

    void saveEntry(const QString &category, double amout, int id);
    void editEntry(const QString &category, double amount, int id);
    bool finishUpEntrys(const QString &month, int year);
    void deleteEntry(int id);
    bool checkCategoryWhitelist(const QString &category);
    bool checkEntryCorrectnes(const QString &category, double amount, const QString &errorMessage);
    void addToCategoryWhitelist(const QString &category);

signals:
    void raiseError(const QString &errorMessage);
    void openWhitelistDialog(const QString &message);

private:
    std::unique_ptr<EntryDatahandler> entryDatahandler;
    QStringList categoryWhiteList;

    QString firstLetterToUpper(const QString &month);
};


