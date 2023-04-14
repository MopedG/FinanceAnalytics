#pragma once

#include "qdialog.h"
#include <QDialog>

namespace Ui {
class ErrorMessageBox;
}

class ErrorMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorMessageBox(QWidget *parent = nullptr);
    ~ErrorMessageBox();

    void setErrorMessage(const QString &errorMessage);

signals:
    void enableEntryWindow();

private slots:
    void on_confirmButton_clicked();

private:
    Ui::ErrorMessageBox *ui;
};

