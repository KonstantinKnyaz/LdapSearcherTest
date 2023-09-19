#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ldapsearcherlite.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connectBtn_clicked();

    void on_bindBtn_clicked();

    void on_searchBtn_clicked();

    void on_closeBtn_clicked();

    void searchFin(QString result);

private:
    Ui::MainWindow *ui;

    LdapSearcherLite *ldap;
};
#endif // MAINWINDOW_H
