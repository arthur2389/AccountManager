#include "account_clone.h"
#include "ui_account_clone.h"

AccountClone::AccountClone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountClone)
{
    ui->setupUi(this);
}

AccountClone::~AccountClone()
{
    delete ui;
}
