#pragma once

#include <QWidget>

namespace Ui {
class MonthCard;
}

class MonthCard : public QWidget
{
    Q_OBJECT

public:
    explicit MonthCard(QWidget *parent = nullptr, const QString &date = "");
    ~MonthCard();

    void deactivate();
    void activate();

signals:
    void monthCardActivated(MonthCard *monthCard);

private slots:
    void on_selectButton_clicked();

private:
    Ui::MonthCard *ui;

    bool buttonChecked = false;
};
