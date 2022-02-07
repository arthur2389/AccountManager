#include "account_model.h"

using namespace std;

AccountModel::AccountModel(QString name,
                           QString email,
                           QString password,
                           QString username) :
    m_name{name}, m_email{email}, m_password{password}, m_username{username}
{}

AccountModel::AccountModel(QString name) : m_name{name}, m_email{}, m_password{}, m_username{}
{}

AccountModel::AccountModel() : m_name{}, m_email{}, m_password{}, m_username{}
{}

void AccountModel::set_username(QString username)
{
    m_username = username;
}

void AccountModel::set_email(QString email)
{
    m_email = email;
}

void AccountModel::set_password(QString password)
{
    m_password = password;
}

QString AccountModel::get_name() const
{
    return m_name;
}

QString AccountModel::get_email() const
{
    return m_email;
}

QString AccountModel::get_username() const
{
    return m_username;
}

QString AccountModel::get_password() const
{
    return m_password;
}

std::ostream& operator<<(std::ostream &os, const AccountModel& acc)
{
    os << "Account: " << acc.get_name().toStdString() << " Email: " << acc.get_email().toStdString() << " Password: " << acc.get_password().toStdString() << " Username: " << acc.get_username().toStdString();
    return os;
}
