#include <QString>
#include <QComboBox>
#include <QPushButton>
#include "mainwindow.h"
#include "account_model.h"
#include "account_set.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(std::shared_ptr<Moderator> moderator, QWidget *parent)
    : QMainWindow(parent),
      mod(moderator),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    load_items();

    // Define actions
    connect(ui->accountBox, &QComboBox::currentTextChanged, this, &MainWindow::display_account);
    connect(ui->editAccount, &QPushButton::clicked, this, [this]() {
        this->set_account(this->ui->accountBox->currentText());
    });
    connect(ui->addAccount, &QPushButton::clicked, this, [this]() {
        this->set_account(QString());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_items() const
{
    ui->accountBox->clear();
    ui->accountBox->addItem("");

    for (const auto& n: mod->get_account_names())
    {
        ui->accountBox->addItem(n);
    }
}

void MainWindow::display_account() const
{
    QString curr = ui->accountBox->currentText();
    QString empty{QString()};
    if (curr.isEmpty())
    {
        ui->lineEditEmail->setText(empty);
        ui->lineEditPassword->setText(empty);
        ui->lineEditUsername->setText(empty);
    }
    else {
        AccountModel curr_account = mod->get_account(curr);
        ui->lineEditEmail->setText(curr_account.get_email());
        ui->lineEditPassword->setText(curr_account.get_password());
        ui->lineEditUsername->setText(curr_account.get_username());
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
