#include "remove_account.h"
#include "ui_remove_account.h"

RemoveAccount::RemoveAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveAccount)
{
    ui->setupUi(this);
}

RemoveAccount::~RemoveAccount()
{
    delete ui;
}
