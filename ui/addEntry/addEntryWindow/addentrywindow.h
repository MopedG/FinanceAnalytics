#pragma once

#include <QWidget>

class EntryForm;
namespace Ui {
class addEntryWindow;
}

class AddEntryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddEntryWindow(QWidget *parent = nullptr);
    ~AddEntryWindow();

private slots:
    void on_openNewEntryForm();

private:
    Ui::addEntryWindow *ui;
    EntryForm *entryForm;

    void setEntryFormAttributes();
    void setUpConnections();
};


