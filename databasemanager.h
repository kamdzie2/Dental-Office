#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMessageBox>


class DataBaseManager : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase m_db;
    QString m_connectionName;
    QString m_driver;
    QString m_hostName;
    QString m_databaseName;
    QString m_userName;
    QString m_password;
    int m_port;

public:
    explicit DataBaseManager(QObject *parent = nullptr);
    ~DataBaseManager();

    void setConnectionPar(const QString& driver,const QString& hostName, const QString& databaseName, const QString& userName, const QString& password, int port =3306);

    bool openConnection();
    void closeConnection();
    bool isOpen() const;
    QSqlError getLastError() const;
    QSqlDatabase getDatabase() const;


signals:
};

#endif // DATABASEMANAGER_H
