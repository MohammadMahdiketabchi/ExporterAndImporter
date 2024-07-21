#ifndef USER_TABLE_H
#define USER_TABLE_H
#include "BaseTable.h"

class UserTable : public BaseTable {
public:
    UserTable(QMap<int, int>* groupIdMap);
    void exportToBinary(const QString& fileName) override;
    void importFromBinary(const QString& fileName, QMap<int, int>* idMap = nullptr) override;
    bool valid_ip(const QString& ip)
    {
        std::regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        std::regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");
        if (std::regex_match(ip.toStdString(),ipv4))
            return true;
        if (std::regex_match(ip.toStdString(),ipv6))
            return true;
        return false;

    }

private:
    QMap<int, int>* groupIdMap;


};

#endif // USER_TABLE_H
