#pragma once

#include <QWidget>

namespace Ui {
class MonthCard;
}

class MonthCard : public QWidget
{
    Q_OBJECT

public:
    explicit MonthCard(QWidget *parent = nullptr);
    ~MonthCard();

private slots:
    void on_selectButton_clicked();

private:
    Ui::MonthCard *ui;

    bool buttonChecked = false;
    void setButtonChecked(bool check = true);
};


