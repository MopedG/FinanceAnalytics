#pragma once
#include <QWidget>
#include <memory>
#include <QCompleter>

namespace Ui {
class EntryForm;
}

class AutoCompleter;
class EntryForm : public QWidget
{
    Q_OBJECT

public:
    explicit EntryForm(QWidget *parent = nullptr, const QStringList &categoryWhitelist = {});
    ~EntryForm();
    void disableCancelEdit(bool disable = true);
    void operationSuccessfull(bool successfull);
    bool checkForUnsibmittedEdit();
    void reset();

    int id = 0;

signals:
    void openEntryForm();
    void closeEntryForm(EntryForm &entryForm);
    void saveEntry(const QString &category, double amount, int id, EntryForm &entryForm);
    void editEntry(const QString &category, double amount, int id, EntryForm &entryForm);

private slots:
    void on_submitButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::EntryForm *ui;
    std::unique_ptr<QCompleter> completer;
    static int instances;
    bool editPressedBefore = false;
    bool entrySaved = false;
    QString currentCategory;
    QString currentAmount;

    void disableFields(bool disable = true);
    QString commaToDot(const QString &amount);

    void setAutoCompletion(const QStringList &categoryWhitelist);
};


