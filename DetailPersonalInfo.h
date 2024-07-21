#ifndef DETAILPERSONALINFO_H
#define DETAILPERSONALINFO_H
#include "BaseTable.h"

class DetailPersonalInfoTable : public BaseTable
{
public:
    DetailPersonalInfoTable(QMap<int, int>* userIdMap);
    void exportToBinary(const QString& fileName) override;
    void importFromBinary(const QString& fileName, QMap<int, int>* idMap = nullptr) override;
private:
    QMap<int, int>* userIdMap;

};

#endif // DETAILPERSONALINFO_H
