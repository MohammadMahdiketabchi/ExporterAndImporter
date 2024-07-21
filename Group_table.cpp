#include "Group_table.h"


GroupTable::GroupTable() {

}

void GroupTable::exportToBinary(const QString& fileName)
{

        QVector<Group> groups;
        dao.getAllGroup(groups);
        Logger::instance().debug("get all data of Group table from database successfully");

        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);

        for (const Group& group : groups) {
            out << group;
        }

        writeToFile(fileName, data);
        Logger::instance().debug("write all data from Group table to file successfully");
}

void GroupTable::importFromBinary(const QString& fileName, QMap<int, int>* idMap)
{
        QByteArray data = readFromFile(fileName);
        QDataStream in(&data, QIODevice::ReadOnly);

        while (!in.atEnd()) {
            struct Group group;
            in >> group;
            int newId = dao.insertToGroup(group.name, group.description,  group.isActive);
            Logger::instance().debug(QString("inserted id: %1 from file to Group table successfully").arg(newId));
            if (idMap) {
                (*idMap)[group.id] = newId;
            }
        }
}

