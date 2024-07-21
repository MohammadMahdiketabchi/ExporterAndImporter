#include "dataaccessobject.h"

DataAccessObject::DataAccessObject()
{
    db_expr = QSqlDatabase::addDatabase("QSQLITE", "export_connection");
    db_expr.setDatabaseName("E:\\New Folder2\\ExxportAndImportV2\\exim.db");

    db_impr = QSqlDatabase::addDatabase("QSQLITE", "import_connection");
    db_impr.setDatabaseName("E:\\New Folder2\\ExxportAndImportV2\\import.db");
}

DataAccessObject::~DataAccessObject()
{
    db_expr.close();
    db_impr.close();
}

DataAccessObject& DataAccessObject::instance()
{
    static DataAccessObject instance;
    return instance;
}

void DataAccessObject::getAllGroup(QVector<struct Group>& groupdata)
{
    groupdata.clear();

    if (!db_expr.open()) {
        Logger::instance().error("can not open export database" + db_expr.lastError().text());
        qWarning() << "Cannot open export database:" << db_expr.lastError().text();
        return;
    }

    QSqlQuery query(db_expr);
    if(!query.exec("SELECT ID, Name, Description, IsActive FROM [Group]")) {
        Logger::instance().error("can not execute select query on Group table" + query.lastError().text());
        qWarning() << "Error executing query:" << query.lastError().text();
        return;
    }

    while (query.next()) {

        struct Group group;
        group.id = query.value(0).toInt();
        group.name = query.value(1).toString();
        group.description = query.value(2).toString();
        group.isActive = query.value(3).toInt();
        groupdata.append(group);
    }

    return;
}

int DataAccessObject::insertToGroup(const QString& name, const QString& description, int isActive)
{
    if (!db_impr.open()) {
        Logger::instance().error("can not open import database" + db_impr.lastError().text());
        qWarning() << "Cannot open import database:" << db_impr.lastError().text();
        return 0;
    }

    QSqlQuery query(db_impr);
    query.prepare("INSERT INTO [Group] (Name, Description, IsActive) VALUES (?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(description);
    query.addBindValue(isActive);

    if (!query.exec()) {
        Logger::instance().error("can not execute insert query on Group table" + query.lastError().text());
        qWarning() << "Insert failed:" << query.lastError().text();
        return 0;
    }

    return query.lastInsertId().toInt();
}

void DataAccessObject::getAllUser(QVector<struct User>& userdata)
{

    if (!db_expr.open()) {
        Logger::instance().error("can not open export database" + db_expr.lastError().text());
        qWarning() << "Cannot open export database:" << db_expr.lastError().text();
        return;
    }

    QSqlQuery query(db_expr);
    if(!query.exec("SELECT ID, Name, IP, Password, GroupID FROM User")) {
        Logger::instance().error("can not execute select query on User table" + query.lastError().text());
        qWarning() << "Error executing query:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        struct User user;
        user.id = query.value(0).toInt();
        user.name = query.value(1).toString();
        user.ip = query.value(2).toString();
        user.password = query.value(3).toString();
        user.groupId = query.value(4).toInt();
        userdata.append(user);
    }

    return;
}

int DataAccessObject::insertToUser(const QString& name, const QString& ip, const QString& password, int groupid)
{
    if (!db_impr.open()) {
        Logger::instance().error("can not open import database" + db_impr.lastError().text());
        qWarning() << "Cannot open import database:" << db_impr.lastError().text();
        return 0;
    }

    QSqlQuery query(db_impr);
    query.prepare("INSERT INTO User (ID, Name, IP, Password, GroupID) VALUES (NULL, ?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(ip);
    query.addBindValue(password);
    query.addBindValue(groupid);

    if (!query.exec()) {
        Logger::instance().error("can not execute insert query on User table" + query.lastError().text());
        qWarning() << "Insert failed:" << query.lastError().text();
        return 0;
    }

    return query.lastInsertId().toInt();
}
void DataAccessObject::getAllDetailPersonalInfo(QVector<struct Detail>& detaildata)
{

    if (!db_expr.open()) {
        Logger::instance().error("can not open export database" + db_expr.lastError().text());
        qWarning() << "Cannot open export database:" << db_expr.lastError().text();
        return;
    }

    QSqlQuery query(db_expr);
    if(!query.exec("SELECT UserID, FirstName, LastName, Office, Phone, PersonnelCode, Address FROM DetailPersonalInfo")) {
        Logger::instance().error("can not execute select query on DetailPersonalInfo table" + query.lastError().text());
        qWarning() << "Error executing query:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        struct Detail detail;
        detail.userId = query.value(0).toInt();
        detail.firstName = query.value(0).toString();
        detail.lastName = query.value(0).toString();
        detail.office = query.value(0).toString();
        detail.phone = query.value(0).toString();
        detail.personnelCode = query.value(0).toString();
        detail.address = query.value(0).toString();
        detaildata.append(detail);
    }

    return;
}

int DataAccessObject::insertToDetailPersonalInfo(int userid, const QString& firstname, const QString& lastname, const QString& office, const QString& phone,const QString& personnelcode,const QString& address)
{
    if (!db_impr.open()) {
        Logger::instance().error("can not open import database" + db_impr.lastError().text());
        qWarning() << "Cannot open import database:" << db_impr.lastError().text();
        return 0;
    }

    QSqlQuery query(db_impr);
    query.prepare("INSERT INTO DetailPersonalInfo (UserID, FirstName, LastName, Office, Phone, PersonnelCode, Address) VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(userid);
    query.addBindValue(firstname);
    query.addBindValue(lastname);
    query.addBindValue(office);
    query.addBindValue(phone);
    query.addBindValue(personnelcode);
    query.addBindValue(address);

    if (!query.exec()) {
        Logger::instance().error("can not execute insert query on DetailPersonalInfo table" + query.lastError().text());
        qWarning() << "Insert failed:" << query.lastError().text();
        return 0;
    }

    return query.lastInsertId().toInt();
}

