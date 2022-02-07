#ifndef ACCOUNT_CLONE_H
#define ACCOUNT_CLONE_H

#include <memory>
#include <QDialog>
#include "moderator.h"
#include "account_model.h"


namespace Ui {
class AccountClone;
}

class AccountClone : public QDialog
{
    Q_OBJECT

public:
    AccountClone(QWidget *parent, std::shared_ptr<Moderator> moderator, QString account_to_clone);
    ~AccountClone();

private slots:
    void on_cloneAccountButtons_accepted();

private:
    Ui::AccountClone *ui;
    std::shared_ptr<Moderator> mod;
    AccountModel acc_to_clone;
};

#endif // ACCOUNT_CLONE_H
