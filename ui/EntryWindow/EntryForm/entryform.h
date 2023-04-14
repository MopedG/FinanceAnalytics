#pragma once
#include <QWidget>

namespace Ui {
class EntryForm;
}

class EntryForm : public QWidget
{
    Q_OBJECT

public:
    explicit EntryForm(QWidget *parent = nullptr);
    ~EntryForm();
    void disableCancelEdit(bool disable = true);
    void operationSuccessfull(bool successfull);
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
    static int instances;
    bool editPressedBefore = false;
    QString currentCategory;
    QString currentAmount;

    void disableFields(bool disable = true);

};


