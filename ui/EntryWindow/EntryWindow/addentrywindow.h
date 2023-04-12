#pragma once

#include <QWidget>
#include <memory>

class EntryController;
class EntryForm;
class EntryData;
class ErrorMessageBox;
class WhiteListMessageBox;
namespace Ui {
class addEntryWindow;
}

class AddEntryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddEntryWindow(QWidget *parent = nullptr, std::vector<std::shared_ptr<EntryData>> data = std::vector<std::shared_ptr<EntryData>>());
    ~AddEntryWindow();


signals:
    void backToMain();

private slots:
    void on_openEntryForm();
    void on_closeEntryForm(EntryForm &entryForm);
    void on_saveEntry(const QString &category, double amount, int id);
    void on_editEntry(const QString &category, double amount, int id, EntryForm &entryForm);
    void on_raiseError(const QString &errorMessage);

    void on_confimAllButton_clicked();
    void on_enableEntryWindow();
    void on_homeButton_clicked();

private:
    Ui::addEntryWindow *ui;
    EntryForm *entryForm;
    std::unique_ptr<ErrorMessageBox> error;
    std::unique_ptr<WhiteListMessageBox> whitelistMessage;
    std::unique_ptr<EntryController> controller;

    void setEntryFormAttributes();
    void connectEntryForm();
    void setUpInitialConnections();
    void initializeClasses(const QStringList &categoryWhiteList);
    void displayError(const QString &errorMessage);
    bool showCategoryWhitelist(const QString &message);
    bool handleCategoryWhitelist(const QString &category, const double amount, EntryForm &entryForm);
    bool openWhitelistDialog(const QString &message);
};


