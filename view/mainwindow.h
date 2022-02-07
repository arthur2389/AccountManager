#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "moderator.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::shared_ptr<Moderator> moderator, QWidget *parent = nullptr);
    ~MainWindow();

private:
    std::shared_ptr<Moderator> mod;
    Ui::MainWindow *ui;

    void set_account(QString acc);
    void clone_account();
    void load_items(void);
    void display_account(void);
    void toggle_account_buttons(bool state);
};
#endif // MAINWINDOW_H
