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
    void backToMain(bool newDataAdded);
    void filePathError();

private slots:
    void on_openEntryForm();
    void on_closeEntryForm(EntryForm &entryForm);
    void on_saveEntry(const QString &category, double amount, int id, EntryForm &entryForm);
    void on_editEntry(const QString &category, double amount, int id, EntryForm &entryForm);
    void on_displayDialog(std::shared_ptr<QDialog> dialog);
    void on_resetEntryForm(EntryForm &entryForm);
    void on_confimAllButton_clicked();
    void on_homeButton_clicked();
    void on_entrySuccessfull(bool successfull, EntryForm &entryForm);

private:
    Ui::addEntryWindow *ui;
    EntryForm *entryForm;
    std::unique_ptr<EntryController> controller;

    void setEntryFormAttributes();
    void connectEntryForm();
    void setUpInitialConnections();
    void initializeClasses(const QStringList &categoryWhiteList);
};


