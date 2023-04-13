#pragma once

#include "qdialog.h"
#include <QDialog>

namespace Ui {
class WhiteListMessageBox;
}

class WhiteListMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit WhiteListMessageBox(QWidget *parent = nullptr);
    ~WhiteListMessageBox();

    void setMessage(const QString &message);
    bool getStatus();

signals:
    void enableEntryWindow();

private slots:
    void on_confirmButton_clicked();

    void on_discardButton_clicked();

private:
    Ui::WhiteListMessageBox *ui;

    bool addToWhitelist = false;
};

