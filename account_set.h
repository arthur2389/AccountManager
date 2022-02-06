#ifndef ACCOUNT_SET_H
#define ACCOUNT_SET_H

#include <QDialog>
#include <QString>
#include <memory>
#include "moderator.h"

QT_BEGIN_NAMESPACE
namespace Ui {class AccountSet;}
QT_END_NAMESPACE

class AccountSet : public QDialog
{
    Q_OBJECT

public:
    AccountSet(QWidget *parent, std::shared_ptr<Moderator> mod, QString account_to_edit);
    ~AccountSet();

private slots:
    void on_newAccountButtons_accepted();

private:
    Ui::AccountSet *ui;
    std::shared_ptr<Moderator> mod;
};

#endif // ACCOUNT_SET_H
