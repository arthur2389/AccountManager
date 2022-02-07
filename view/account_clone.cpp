#include "account_clone.h"
#include "ui_account_clone.h"

AccountClone::AccountClone(QWidget *parent, std::shared_ptr<Moderator> moderator, QString account_to_clone):
    QDialog(parent),
    ui(new Ui::AccountClone),
    mod(moderator)
{
    acc_to_clone = moderator->get_account(account_to_clone);
    ui->setupUi(this);
    setWindowTitle("Clone Account");
}

void AccountClone::on_cloneAccountButtons_accepted(void)
{
    AccountModel cloned = acc_to_clone.clone(ui->lineEditNewAccountName->text());
    mod->set_account(cloned);
}

AccountClone::~AccountClone()
{
    delete ui;
}
