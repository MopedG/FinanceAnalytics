#ifndef SPENDINGFORM_H
#define SPENDINGFORM_H

#include <QWidget>

namespace Ui {
class SpendingForm;
}

class SpendingForm : public QWidget
{
    Q_OBJECT

public:
    explicit SpendingForm(QWidget *parent = nullptr);
    ~SpendingForm();

private:
    Ui::SpendingForm *ui;
};

#endif // SPENDINGFORM_H
