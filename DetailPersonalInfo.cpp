#include "DetailPersonalInfo.h"



DetailPersonalInfoTable::DetailPersonalInfoTable(QMap<int, int>* userIdMap)
{
        this->userIdMap = userIdMap;

}

void DetailPersonalInfoTable::exportToBinary(const QString& fileName)
{
        QVector<Detail> details;
        dao.getAllDetailPersonalInfo(details);
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);
        Logger::instance().debug("get all data of DetailPersonalInfo table from database successfully");


        for (const Detail& detail : details) {

            out << detail;
        }

        writeToFile(fileName, data);
        Logger::instance().debug("write all data from DetailPersonalInfo table to file successfully");

}

void DetailPersonalInfoTable::importFromBinary(const QString& fileName, QMap<int, int>* idMap)
{
        QByteArray data = readFromFile(fileName);
        QDataStream in(&data, QIODevice::ReadOnly);


        while (!in.atEnd()) {
            struct Detail detail;

            in >> detail;

            if (userIdMap->contains(detail.userId)) {
                detail.userId = (*userIdMap)[detail.userId];
            }

            int newId = dao.insertToDetailPersonalInfo(detail.userId, detail.firstName, detail.lastName, detail.office, detail.phone, detail.personnelCode, detail.address);
            Logger::instance().debug(QString("inserted id: %1 from file to DetailPersonalInfo table successfully").arg(newId));


        }
}

