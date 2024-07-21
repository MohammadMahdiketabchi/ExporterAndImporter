#ifndef GROUP_TABLE_H
#define GROUP_TABLE_H
#include "BaseTable.h"



class GroupTable : public BaseTable{
public:
    GroupTable();
    void importFromBinary(const QString& fileName, QMap<int, int>* idMap = nullptr) override;
    void exportToBinary(const QString& fileName) override;

};

#endif // GROUP_TABLE_H
