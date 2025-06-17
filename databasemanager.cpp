#include "databasemanager.h"
#include <QUuid>

DataBaseManager::DataBaseManager(QObject *parent)
    : QObject(parent), m_port(0)
{
    m_connectionName = QUuid::createUuid().toString();
    qDebug() << "DatabaseManager created. Connection name reserved:" << m_connectionName;
}

DataBaseManager::~DataBaseManager()
{
    closeConnection();
    if (QSqlDatabase::contains(m_connectionName))
    {
        QSqlDatabase::removeDatabase(m_connectionName);
        qDebug() << "Połączenie" << m_connectionName << "usunięte z rejestru Qt.";
    }
}

void DataBaseManager::setConnectionPar(const QString& driver, const QString& hostName, const QString& databaseName, const QString& userName, const QString& password,int port)
{
    m_driver = driver;
    m_hostName = hostName;
    m_databaseName = databaseName;
    m_userName = userName;
    m_password = password;
    m_port = port;

    qDebug() << "Parametry połączenia dla" << m_connectionName << "ustawione.";
}

bool DataBaseManager::openConnection()
{
    if (m_driver.isEmpty() || m_hostName.isEmpty() || m_databaseName.isEmpty())
    {
        qDebug() << "BŁĄD: Parametry połączenia nie zostały ustawione przed próbą otwarcia dla" << m_connectionName;
        return false;
    }

    if (QSqlDatabase::contains(m_connectionName))
    {
        m_db = QSqlDatabase::database(m_connectionName);
    } else
    {
        m_db = QSqlDatabase::addDatabase(m_driver, m_connectionName);
    }

    m_db.setHostName(m_hostName);
    m_db.setDatabaseName(m_databaseName);
    m_db.setUserName(m_userName);
    m_db.setPassword(m_password);
    m_db.setPort(m_port);

    if (m_db.isOpen())
    {
        qDebug() << "Połączenie" << m_connectionName << "jest już otwarte (lub zostało ponownie użyte).";
        return true;
    }

    if (m_db.open())
    {
        qDebug() << "SUKCES! Pomyślnie połączono z bazą danych przez połączenie:" << m_connectionName;
        return true;
    }   else
    {
        qDebug() << "BŁĄD! Nie udało się połączyć z bazą danych przez połączenie:" << m_connectionName;
        qDebug() << "Błąd Qt:" << m_db.lastError().text();
        return false;
    }
}

void DataBaseManager::closeConnection()
{
    if (m_db.isValid() && m_db.isOpen())
    {
        m_db.close();
        qDebug() << "Połączenie" << m_connectionName << "zamknięte.";
    }
}

bool DataBaseManager::isOpen() const
{
    return m_db.isValid() && m_db.isOpen();
}

QSqlError DataBaseManager::getLastError() const
{
    return m_db.lastError();
}

QSqlDatabase DataBaseManager::getDatabase() const
{
    return m_db;
}
