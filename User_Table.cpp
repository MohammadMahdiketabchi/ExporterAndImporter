#include "User_Table.h"


UserTable::UserTable(QMap<int, int>* groupIdMap)
{
        this->groupIdMap = groupIdMap;
}

void UserTable::exportToBinary(const QString& fileName)
{
        QVector<User> users;
        dao.getAllUser(users);
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);
        Logger::instance().debug("get all data of User table from database successfully");


        for (const User& user : users) {

            if(!valid_ip(user.ip))
                Logger::instance().warn("ip:" + user.ip +" of user " + user.name + " is not valid");
            out << user;
        }

        writeToFile(fileName, data);
        Logger::instance().debug("write all data from User table to file successfully");

}

void UserTable::importFromBinary(const QString& fileName, QMap<int, int>* idMap)
{
        QByteArray data = readFromFile(fileName);
        QDataStream in(&data, QIODevice::ReadOnly);

        while (!in.atEnd()) {
            struct User user;
            in >> user;

            if (this->groupIdMap->contains(user.groupId)) {
                user.groupId = (*groupIdMap)[user.groupId];
            }

            int newId = dao.insertToUser(user.name, user.ip, user.password, user.groupId);
            Logger::instance().debug(QString("inserted id: %1 from file to User table successfully").arg(newId));

            if (idMap) {
                (*idMap)[user.id] = newId;
            }
        }
}
