#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QListWidget>
#include "ErreurSousResponsable.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //creer et connect à muSql maze
    QSqlDatabase  db =QSqlDatabase::addDatabase("QSQLITE");    // type
                  db.setDatabaseName("maze");                     //nom de database
                  db.setHostName("127.0.0.1");                    //Host
                  db.setPort(3306);                               //Porte
                  db.setUserName("root");                         //login
                  db.setPassword("root");                         //mot de passe
    if (! db.open()) {
        qDebug()<<"open database error!";
        return;
    }
    else{
        qDebug()<<"open database success!";
    }

    //creer tableau erreur
    QSqlQuery sqlQuery;
    // preparer exec
    QString createSql = QString("CREATE TABLE Erreurs (\
                              id INT PRIMARY KEY NOT NULL,\
                              apercu TEXT NOT NULL)");
    sqlQuery.prepare(createSql);
    // creer tableau
    if(!sqlQuery.exec())
    {
        qDebug() << "Défaut de création d’une table. " << sqlQuery.lastError();
    }
    else
    {     qDebug() << "Tableau créé!";  }

    //inserer
    if(!sqlQuery.exec("INSERT INTO Erreurs VALUES(0, \" manque responsable \")"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Insertion!";
    }

    //creer tableau producteur
    // preparer exec
    QString createSqlProducteur = QString("CREATE TABLE Producteurs (\
                              id INT PRIMARY KEY NOT NULL,\
                              boutiqueId INT NOT NULL, \
                              LivraisonsId INT NOT NULL, \
                              payment FLOAT NOT NULL)");
    sqlQuery.prepare(createSqlProducteur);
    // creer tableau
    if(!sqlQuery.exec())
    {
        qDebug() << "Défaut de création d’une table. " << sqlQuery.lastError();
    }
    else
    {     qDebug() << "Tableau créé!";  }

    //inserer
    if(!sqlQuery.exec("INSERT INTO Producteurs VALUES(0, 1,1,1000)"))
    {
        qDebug() << "Erreur: Défaut de insertion d’une table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Insertion!";
    }

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_ConsulterReports_clicked()
{
    QSqlQuery query;

    query.exec("select * from Erreurs");
    while(query.next())
    {
        QString  id= query.value(0).toString();
        QString  apercu= query.value(1).toString();
        qDebug()<<id<<apercu;

     //   aItem=new QListWidgetItem();
     //   aItem->setText(apercu);
     //   ui->SousList->addItem(aItem);
        ErreurSousResponsable* pItemWidget = new ErreurSousResponsable(this);
        pItemWidget->setData(apercu);
        QListWidgetItem* pItem = new QListWidgetItem();
        pItem->setSizeHint(QSize(240, 120));
        ui->SousList->addItem(pItem);
        ui->SousList->setItemWidget(pItem,pItemWidget);

    }
}

