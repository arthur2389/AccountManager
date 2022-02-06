#ifndef MODERATOR_H
#define MODERATOR_H

#include <map>
#include <QString>
#include <vector>
#include "account_model.h"


class Moderator
{
public:
    Moderator(std::vector<AccountModel> accounts);
    Moderator(Moderator& other);
    // const AccountModel& load_account() const {};
    AccountModel build_empty_account(QString name) const;
    const AccountModel& get_account(QString name) const;
    std::vector<QString> get_account_names() const;
    void set_account(AccountModel& account);


private:
    std::map<QString, AccountModel> acc;
};

#endif // MODERATOR_H
