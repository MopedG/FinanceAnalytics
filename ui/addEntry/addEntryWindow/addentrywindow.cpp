#include "addentrywindow.h"
#include "addEntry/addEntryForm/entryform.h"
#include "ui_addentrywindow.h"

AddEntryWindow::AddEntryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addEntryWindow)
{
    ui->setupUi(this);
    on_openNewEntryForm();
}

AddEntryWindow::~AddEntryWindow()
{
    delete ui;
}

void AddEntryWindow::on_openNewEntryForm()
{
    entryForm = new EntryForm(this);
    setEntryFormAttributes();
    setUpConnections();
}

void AddEntryWindow::setEntryFormAttributes()
{
    ui->cellLayout_2->setAlignment(Qt::AlignTop);
    ui->cellLayout_2->addWidget(entryForm, 0, Qt::AlignTop);
    entryForm->setAttribute(Qt::WA_DeleteOnClose, true);
    entryForm->disableCancelEdit();
}

void AddEntryWindow::setUpConnections()
{
    AddEntryWindow::connect(entryForm, &EntryForm::openNewEntryForm, this, &AddEntryWindow::on_openNewEntryForm);
}
