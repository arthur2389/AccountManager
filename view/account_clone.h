#ifndef ACCOUNT_CLONE_H
#define ACCOUNT_CLONE_H

#include <QDialog>

namespace Ui {
class AccountClone;
}

class AccountClone : public QDialog
{
    Q_OBJECT

public:
    explicit AccountClone(QWidget *parent = nullptr);
    ~AccountClone();

private:
    Ui::AccountClone *ui;
};

#endif // ACCOUNT_CLONE_H
