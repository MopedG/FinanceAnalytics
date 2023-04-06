#pragma once

#include "EntryWindow/EntryDatahandler/entrydatahandler.h"

#include <QObject>

class EntryController : public QObject
{
    Q_OBJECT

public:
    EntryController();
    ~EntryController() = default;

    bool saveEntry(const QString &category, double amout, int id);
    bool editEntry(const QString &category, double amount, int id);
    bool finishUpEntrys(const QString &month, int year);
    void deleteEntry(int id);

signals:
    void raiseError(const QString &errorMessage);

private:
    std::unique_ptr<EntryDatahandler> entryDatahandler;

    QString formatMonth(const QString &month);
};


