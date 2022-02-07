#include "moderator.h"

Moderator::Moderator(std::vector<AccountModel> accounts)
{
    for (auto ac: accounts)
    {
        acc.insert({ac.get_name(), ac});
    }
}

Moderator::Moderator(Moderator& other)
{}

AccountModel Moderator::build_empty_account(QString name) const
{
    return AccountModel(name);
}

const AccountModel& Moderator::get_account(QString name) const
{
    return acc.at(name);
}

std::vector<QString> Moderator::get_account_names() const
{
    std::vector<QString>names;
    for (auto i: acc)
    {
        names.push_back(i.first);
    }

    return names;
}

void Moderator::set_account(AccountModel &account)
{
    acc[account.get_name()] = account;
}
