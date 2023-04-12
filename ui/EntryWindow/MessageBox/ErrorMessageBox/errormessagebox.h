#pragma once

#include <QWidget>

namespace Ui {
class ErrorMessageBox;
}

class ErrorMessageBox : public QWidget
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

