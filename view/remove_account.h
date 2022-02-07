#ifndef REMOVE_ACCOUNT_H
#define REMOVE_ACCOUNT_H

#include <QDialog>

namespace Ui {
class RemoveAccount;
}

class RemoveAccount : public QDialog
{
    Q_OBJECT

public:
    RemoveAccount(QWidget *parent, QString acc_to_remove);
    ~RemoveAccount();

private:
    Ui::RemoveAccount *ui;
};

#endif // REMOVE_ACCOUNT_H
