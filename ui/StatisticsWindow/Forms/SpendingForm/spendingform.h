#pragma once
#include <QWidget>

namespace Ui {
class SpendingForm;
}

class SpendingForm : public QWidget
{
    Q_OBJECT

public:
    explicit SpendingForm(QWidget *parent = nullptr, const QString &category = "", double amount = 0);
    ~SpendingForm();


private:
    Ui::SpendingForm *ui;
};


