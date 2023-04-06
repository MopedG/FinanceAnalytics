#pragma once

#include <QWidget>
#include <memory>

class EntryController;
class EntryForm;
class ErrorMessageBox;
namespace Ui {
class addEntryWindow;
}

class AddEntryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddEntryWindow(QWidget *parent = nullptr);
    ~AddEntryWindow();


signals:
    void backToMain();

private slots:
    void on_openEntryForm();
    void on_closeEntryForm(EntryForm &entryForm);
    void on_saveEntry(const QString &category, double amount, int id);
    void on_editEntry(const QString &category, double amount, int id);
    void on_raiseError(const QString &errorMessage);
    void on_confimAllButton_clicked();
    void on_enableEntryWindow();

    void on_homeButton_clicked();

private:
    Ui::addEntryWindow *ui;
    EntryForm *entryForm;
    std::unique_ptr<ErrorMessageBox> error;
    std::unique_ptr<EntryController> controller;


    void setEntryFormAttributes();
    void connectEntryForm();
    void setUpInitialConnections();
    void initializeClasses();
    void displayError(const QString &errorMessage);
};


