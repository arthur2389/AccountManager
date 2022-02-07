#ifndef ACCOUNT_MODEL_H
#define ACCOUNT_MODEL_H


#include <QString>


class AccountModel
{
public:
    AccountModel(QString name,
                 QString email,
                 QString password,
                 QString username);
    AccountModel(QString name);
    AccountModel();
    AccountModel clone(QString name=QString());
    void set_username(QString username);
    void set_email(QString email);
    void set_password(QString password);
    QString get_name() const;
    QString get_username() const;
    QString get_email() const;
    QString get_password() const;

private:
    QString m_name;
    QString m_email;
    QString m_password;
    QString m_username;
};

std::ostream& operator<<(std::ostream &os, const AccountModel& acc);

#endif // ACCOUNT_MODEL_H
