#include <QString>
#include <QComboBox>
#include <QPushButton>
#include "mainwindow.h"
#include "account_model.h"
#include "account_set.h"
#include "account_clone.h"
#include "remove_account.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(std::shared_ptr<Moderator> moderator, QWidget *parent)
    : QMainWindow(parent),
      mod(moderator),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Account Manager");
    toggle_account_buttons(false);

    load_items();

    // Define actions
    connect(ui->accountBox, &QComboBox::currentTextChanged, this, &MainWindow::display_account);
    connect(ui->editAccount, &QPushButton::clicked, this, [this]() {
        this->set_account(this->ui->accountBox->currentText());
    });
    connect(ui->addAccount, &QPushButton::clicked, this, [this]() {
        this->set_account(QString());
    });
    connect(ui->cloneAccount, &QPushButton::clicked, this, &MainWindow::clone_account);
    connect(ui->removeAccount, &QPushButton::clicked, this, [this]() {
        QString curr_account = this->ui->accountBox->currentText();
        RemoveAccount* rem_acc = new RemoveAccount(this, curr_account);
        if (rem_acc->exec())
            mod->remove_account(curr_account);

        load_items();
        display_account();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_items(void)
{
    ui->accountBox->clear();
    ui->accountBox->addItem("");

    for (const auto& n: mod->get_account_names())
    {
        ui->accountBox->addItem(n);
    }
}

void MainWindow::display_account(void)
{
    QString curr = ui->accountBox->currentText();
    QString empty{QString()};
    if (curr.isEmpty())
    {
        ui->lineEditEmail->setText(empty);
        ui->lineEditPassword->setText(empty);
        ui->lineEditUsername->setText(empty);
        toggle_account_buttons(false);
        ui->editAccount->setStatusTip(QString());
        ui->cloneAccount->setStatusTip(QString());
        ui->removeAccount->setStatusTip(QString());
    }
    else {
        AccountModel curr_account = mod->get_account(curr);
        ui->lineEditEmail->setText(curr_account.get_email());
        ui->lineEditPassword->setText(curr_account.get_password());
        ui->lineEditUsername->setText(curr_account.get_username());
        toggle_account_buttons(true);
        ui->editAccount->setStatusTip("Edit account '" + curr + "' ");
        ui->cloneAccount->setStatusTip("Clone data from '" + curr + "' to new account");
        ui->removeAccount->setStatusTip("Remove account '" + curr + "'");
    }
}

void MainWindow::set_account(QString acc)
{
    AccountSet* acc_set = new AccountSet(this, mod, acc);

    if (acc_set->exec())
    {
        load_items();
        display_account();
    }
}

void MainWindow::clone_account()
{
    AccountClone* acc_clone = new AccountClone(this, mod, this->ui->accountBox->currentText());

    if (acc_clone->exec())
    {
        load_items();
        display_account();
    }
}

void MainWindow::toggle_account_buttons(bool state)
{
    ui->cloneAccount->setEnabled(state);
    ui->editAccount->setEnabled(state);
    ui->removeAccount->setEnabled(state);
}
