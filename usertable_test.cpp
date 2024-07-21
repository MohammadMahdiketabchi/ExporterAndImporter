#include <gtest/gtest.h>
#include "User_Table.h"
#include "Group_table.h"
#include <QFile>
#include <QDir>

// class UserTableTest : public ::testing::Test {
// protected:
//     void SetUp() override {
//         testFileName = "test_user_table.dat";

//         GroupTable groupTable;
//         groupTable.exportToBinary(groupTestFileName);
//         groupIdMap = new QMap<int, int>();
//         groupTable.importFromBinary(groupTestFileName, groupIdMap);

//         UserTable userTable(groupIdMap);
//         userTable.exportToBinary(testFileName);
//     }

//     void TearDown() override {
//         QFile::remove(testFileName);
//         QFile::remove(groupTestFileName);
//         delete groupIdMap;
//     }

//     QString testFileName;
//     QString groupTestFileName = "test_group_table.dat";
//     QMap<int, int>* groupIdMap;
// };

// TEST_F(UserTableTest, ExportToBinary) {
//     UserTable userTable(groupIdMap);
//     QString exportFileName = "export_test_user_table.dat";

//     userTable.exportToBinary(exportFileName);

//     QFile file(exportFileName);
//     ASSERT_TRUE(file.exists()) << "Export file does not exist.";
//     ASSERT_GT(file.size(), 0) << "Export file is empty.";

//     file.remove();
// }

// TEST_F(UserTableTest, ImportFromBinary) {
//     UserTable userTable(groupIdMap);
//     QMap<int, int> idMap;

//     userTable.importFromBinary(testFileName, &idMap);

//     ASSERT_FALSE(idMap.isEmpty()) << "ID map is empty after import.";

//     QVector<QVariantList> users = userTable.dao.getAllUser();
//     ASSERT_GT(users.size(), 0) << "No users found after import.";
// }
TEST(UserTableTest, ValidIpv4)
{
    QMap<int, int>* groupIdMap;
    UserTable userTable(groupIdMap);
    EXPECT_TRUE(userTable.valid_ip("192.168.1.1"));
    EXPECT_TRUE(userTable.valid_ip("0.0.0.0"));
    EXPECT_TRUE(userTable.valid_ip("255.255.255.255"));
}

TEST(UserTableTest, ValidIPv6) {
    QMap<int, int>* groupIdMap;
    UserTable userTable(groupIdMap);
    EXPECT_TRUE(userTable.valid_ip("2001:0db8:85a3:0000:0000:8a2e:0370:7334"));
}

TEST(UserTableTest, InvalidIPs) {
    QMap<int, int>* groupIdMap;
    UserTable userTable(groupIdMap);
    EXPECT_FALSE(userTable.valid_ip("256.256.256.256"));
    EXPECT_FALSE(userTable.valid_ip("192.168.1.1.1"));
    EXPECT_FALSE(userTable.valid_ip("1234::1234::1234"));
    EXPECT_FALSE(userTable.valid_ip("invalid_ip"));

}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
