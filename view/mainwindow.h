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

    void load_items(void) const;
    void display_account(void) const;
    void set_account(QString acc);
};
#endif // MAINWINDOW_H
