#pragma once

#include "EntryWindow/EntryDatahandler/entrydatahandler.h"
#include "qdialog.h"

#include <QObject>

class EntryForm;
class ErrorMessageBox;
class WhiteListMessageBox;
class EntryController : public QObject
{
    Q_OBJECT

public:
    EntryController(QStringList categoryWhiteList);
    ~EntryController() = default;

    void saveEntry(const QString &category, double amout, int id, EntryForm &entryForm);
    void editEntry(const QString &category, double amount, int id, EntryForm &entryForm);
    bool finishUpEntrys(const QString &month, int year, bool unsubmittedEdits);
    void deleteEntry(int id);
    bool checkEntryCorrectnes(const QString &category, double amount, const QString &errorMessage);
    void addToCategoryWhitelist(const QString &category);

signals:
    void displayDialog(std::shared_ptr<QDialog> dialog);
    void entrySuccessfull(bool successfull, EntryForm &entryForm);
    void resetEntryForm(EntryForm &entryForm);
    void filePathError();

private:
    std::unique_ptr<EntryDatahandler> entryDatahandler;
    QStringList categoryWhiteList;
    std::shared_ptr<WhiteListMessageBox> whitelistDialog;
    std::shared_ptr<ErrorMessageBox> errorDialog;

    QString firstLetterToUpper(const QString &month);
};


