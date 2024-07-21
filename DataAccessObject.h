#ifndef DATAACCESSOBJECT_H
#define DATAACCESSOBJECT_H
#include <QString>
#include <QFile>
#include <QDataStream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include "logger.h"

struct Group{
    int id;
    QString name;
    QString description;
    int isActive;

    friend QDataStream &operator<<(QDataStream &out,const Group& groupstr)
    {
        return out << groupstr.id << groupstr.name << groupstr.description << groupstr.isActive;
    }
    friend QDataStream &operator>>(QDataStream &in,Group& groupstr)
    {
        return in >> groupstr.id >> groupstr.name >> groupstr.description >> groupstr.isActive;
    }

};

struct User
{
    int id;
    QString name;
    QString ip;
    QString password;
    int groupId;

    friend QDataStream &operator<<(QDataStream &out,const User& userstr)
    {
        return out << userstr.id << userstr.name << userstr.ip << userstr.password << userstr.groupId;
    }
    friend QDataStream &operator>>(QDataStream &in,User& userstr)
    {
        return in >> userstr.id >> userstr.name >> userstr.ip >> userstr.password >> userstr.groupId;
    }

};

struct Detail
{
    int userId;
    QString firstName;
    QString lastName;
    QString office;
    QString phone;
    QString personnelCode;
    QString address;

    friend QDataStream &operator<<(QDataStream &out,const Detail& detailstr)
    {
        return out << detailstr.userId << detailstr.firstName << detailstr.lastName << detailstr.office << detailstr.phone << detailstr.personnelCode << detailstr.address;
    }

    friend QDataStream &operator>>(QDataStream &in,Detail& detailstr)
    {
        return in >> detailstr.userId >> detailstr.firstName >> detailstr.lastName >> detailstr.office >> detailstr.phone >> detailstr.personnelCode >> detailstr.address;

    }


};




class DataAccessObject
{
public:
    DataAccessObject();
    ~DataAccessObject();
    static DataAccessObject& instance();
    void getAllGroup(QVector<struct Group>& groupdata);
    int insertToGroup(const QString& name, const QString& description, int isActive);
    void getAllUser(QVector<struct User>& userdata);
    int insertToUser(const QString& name, const QString& ip, const QString& password, int groupid);
    void getAllDetailPersonalInfo(QVector<struct Detail>& detaildata);
    int insertToDetailPersonalInfo(int userid, const QString& firstname, const QString& lastname, const QString& office, const QString& phone,const QString& personnelcode,const QString& address);



private:
    QSqlDatabase db_expr;
    QSqlDatabase db_impr;
};

#endif // DATAACCESSOBJECT_H
