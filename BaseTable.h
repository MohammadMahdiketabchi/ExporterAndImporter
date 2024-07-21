#ifndef BASETABLE_H
#define BASETABLE_H

#include <QString>
#include <QFile>
#include <QDataStream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QMap>
#include <regex>
#include "dataaccessobject.h"


class BaseTable {
public:
    virtual ~BaseTable() = default;

    virtual void exportToBinary(const QString& fileName) = 0;
    virtual void importFromBinary(const QString& fileName, QMap<int, int>* idMap=nullptr) = 0;
    DataAccessObject& dao = DataAccessObject::instance();


protected:
    void writeToFile(const QString& fileName, const QByteArray& data) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            Logger::instance().error("cannot open file for writing: " + file.errorString());
            qWarning() << "Cannot open file for writing:" << file.errorString();
            return;
        }
        QDataStream out(&file);
        out.writeRawData(data.constData(), data.size());
    }

    QByteArray readFromFile(const QString& fileName) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            Logger::instance().error("cannot open file for reading: " + file.errorString());
            qWarning() << "Cannot open file for reading:" << file.errorString();
            return {};
        }
        QDataStream in(&file);
        QByteArray data;
        data.resize(file.size());
        in.readRawData(data.data(), data.size());
        return data;
    }
};


#endif // BASETABLE_H
