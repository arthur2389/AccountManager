#include "account_set.h"
#include "ui_account_set.h"
#include <QDebug>
#include <iostream>

AccountSet::AccountSet(QWidget *parent, std::shared_ptr<Moderator> moderator, QString account_to_edit):
    QDialog(parent),
    ui(new Ui::AccountSet),
    mod(moderator)
{
    ui->setupUi(this);
    setWindowTitle("Set Account");

    // Emply string means adding new account
    if (!account_to_edit.isEmpty())
    {
        AccountModel account = mod->get_account(account_to_edit);
        ui->lineEditAccountName->setText(account.get_name());
        ui->lineEditAccountName->setDisabled(true);
        ui->lineEditEmil->setText(account.get_email());
        ui->lineEditPassword->setText(account.get_password());
        ui->lineEditUsername->setText(account.get_username());
    }

}

AccountSet::~AccountSet()
{
    delete ui;
}

void AccountSet::on_newAccountButtons_accepted()
{
    if (ui->lineEditAccountName->text().isEmpty()) return;

    AccountModel acc = mod->build_empty_account(ui->lineEditAccountName->text());


    acc.set_email(ui->lineEditEmil->text());
    acc.set_password(ui->lineEditPassword->text());
    acc.set_username(ui->lineEditUsername->text());

    mod->set_account(acc);
}

