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

    void disableCancelEdit();

signals:
    void openNewEntryForm();

private slots:
    void on_submitButton_clicked();

private:
    Ui::EntryForm *ui;
};


