#pragma once
#include <QWidget>

namespace Ui {
class SpendingForm;
}

class SpendingForm : public QWidget
{
    Q_OBJECT

public:
    explicit SpendingForm(QWidget *parent = nullptr, const QString &category = "", double amount = 0, const QString &dateChanged = "No Data");
    ~SpendingForm();


private slots:
    void on_category_clicked();

private:
    Ui::SpendingForm *ui;
    std::unique_ptr<QTimer> timerHideLastChanged;

    void setUpLastChanged(const QString &text);
    void hideLastChangedAfterMilliSeconds(int milliseconds);
};


