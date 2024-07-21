#ifndef TABLE_FACTORY_H
#define TABLE_FACTORY_H

#include "Group_table.h"
#include "User_Table.h"
#include "DetailPersonalInfo.h"


enum class TableName {
    Group,
    User,
    DetailPersonalInfo,
    Unknown
};


class TableFactory {
public:
    static std::unique_ptr<BaseTable> createTable(TableName tablecode,QMap<int, int>* groupIdMap, QMap<int, int>* userIdMap) {
        switch (tablecode) {
        case TableName::Group:
            return std::make_unique<GroupTable>();
        case TableName::User:
            return std::make_unique<UserTable>(groupIdMap);
        case TableName::DetailPersonalInfo:
            return std::make_unique<DetailPersonalInfoTable>(userIdMap);
        default:
            return nullptr;
        }

        // Add more tables here
        return nullptr;
    }
};

#endif // TABLE_FACTORY_H
