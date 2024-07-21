#ifndef APPLICATION_H
#define APPLICATION_H

#include "Table_Factory.h"

class Application
{
public:
    Application(const QString& mode);
    void execute();
    void exportAll();
    void importAll();
    void exportTable(TableName tableCode, const QString& fileName);
    void importTable(TableName tableCode, const QString& fileName, QMap<int, int>* idMap);

private:
    QString mode;
    QMap<int, int> groupIdMap;
    QMap<int, int> userIdMap;


};

#endif // APPLICATION_H
