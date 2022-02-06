#include <memory>
#include <vector>
#include <QApplication>
#include <QFont>
#include "mainwindow.h"
#include "moderator.h"
#include "account_model.h"


int main(int argc, char *argv[])
{
    // Build accounts to show
    std::vector<AccountModel> acc;
    acc.push_back(AccountModel("gmail", "rtur2389@gmail.com", "122022Arthur", ""));
    acc.push_back(AccountModel("wdc", "artur.ferber@wdc.com", "122022Arthur", ""));
    acc.push_back(AccountModel("meitav", "rtur2389@gmail.com", "345rertw", "7500"));

    std::shared_ptr<Moderator> mod = std::make_shared<Moderator>(acc);

    QFont font;
    font.setPointSize(12);

    QApplication a(argc, argv);
    a.setFont(font);
    MainWindow w{mod};
    w.show();
    return a.exec();
}
