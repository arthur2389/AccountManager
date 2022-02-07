#include "remove_account.h"
#include "ui_remove_account.h"

RemoveAccount::RemoveAccount(QWidget *parent, QString acc_to_remove) :
    QDialog(parent),
    ui(new Ui::RemoveAccount)
{
    ui->setupUi(this);
    ui->removeAccountMsg->setText("Account '" + acc_to_remove + "' will be removed");
}

RemoveAccount::~RemoveAccount()
{
    delete ui;
}
