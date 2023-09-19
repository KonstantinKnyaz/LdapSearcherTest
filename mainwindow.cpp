#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ldap = new LdapSearcherLite();

    connect(ldap, &LdapSearcherLite::searchFinish, this, &MainWindow::searchFin);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ldap;
}


void MainWindow::on_connectBtn_clicked()
{
    const QString url = "ldap://172.2.0.50:3268";
    int res = ldap->LDInit(url);

    if(res != LDAP_SUCCESS) {
        qCritical() << "Не удалось подключится к серверу";
        return;
    }
    qInfo() << "Успех!";
}


void MainWindow::on_bindBtn_clicked()
{
    int res = ldap->LDBind("ldap-query","ldap-query");
    if(res != LDAP_SUCCESS) {
        qCritical() << "Бинд не удался";
        return;
    }
    qInfo() << "Успех!";
}


void MainWindow::on_searchBtn_clicked()
{
    int res = ldap->LDMailSearch(ui->lineEdit->text());

    if(res != LDAP_SUCCESS) {
        qCritical() << "Поиск не удался";
        return;
    }
    qInfo() << "Успех!";
}


void MainWindow::on_closeBtn_clicked()
{
    int res = ldap->LDClose();

    if(res != LDAP_SUCCESS) {
        qCritical() << "Анбинд не удался";
        return;
    }
    qInfo() << "Успех!";
}

void MainWindow::searchFin(QString result)
{
    ui->textEdit->setPlainText(result);
}

