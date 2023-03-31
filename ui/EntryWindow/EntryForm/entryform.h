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

    int id = 0;

    void disableCancelEdit(bool disable = true);

signals:
    void openEntryForm();
    void closeEntryForm(EntryForm &entryForm);
    void saveEntry(const QString &category, double amount, int id);
    void editEntry(const QString &category, double amount, int id);

private slots:
    void on_submitButton_clicked();

    void on_editButton_clicked();


    void on_deleteButton_clicked();

private:
    Ui::EntryForm *ui;

    void disableFields(bool disable = true);

    static int instances;
    bool editPressedBefore = false;
};


