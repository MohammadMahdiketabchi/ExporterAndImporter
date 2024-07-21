// #include <gtest/gtest.h>
// #include "DetailPersonalInfo.h"
// #include "User_Table.h"
// #include "Group_table.h"
// #include <QFile>
// #include <QDir>

// class DetailPersonalInfoTableTest : public ::testing::Test {
// protected:
//     void SetUp() override {
//         testFileName = "test_detailpersonalinfo_table.dat";

//         GroupTable groupTable;
//         groupTable.exportToBinary(groupTestFileNmae);
//         groupTable.importFromBinary(groupTestFileNmae,&groupIdMap);
//         UserTable userTable(&groupIdMap);
//         userTable.exportToBinary(userTestFileName);
//         userTable.importFromBinary(userTestFileName, &userIdMap);

//         DetailPersonalInfoTable detailTable(&userIdMap);
//         detailTable.exportToBinary(testFileName);
//     }

//     void TearDown() override {
//         QFile::remove(testFileName);
//         QFile::remove(userTestFileName);
//     }

//     QString testFileName;
//     QString userTestFileName = "test_user_table.dat";
//     QString groupTestFileNmae = "test_group_table.dat";

//     QMap<int, int> userIdMap;
//     QMap<int, int> groupIdMap;

// };

// TEST_F(DetailPersonalInfoTableTest, ExportToBinary) {
//     DetailPersonalInfoTable detailTable(&userIdMap);
//     QString exportFileName = "export_test_detailpersonalinfo_table.dat";

//     detailTable.exportToBinary(exportFileName);

//     QFile file(exportFileName);
//     ASSERT_TRUE(file.exists()) << "Export file does not exist.";
//     ASSERT_GT(file.size(), 0) << "Export file is empty.";

//     file.remove();
// }

// TEST_F(DetailPersonalInfoTableTest, ImportFromBinary) {
//     DetailPersonalInfoTable detailTable(&userIdMap);
//     QMap<int, int> idMap;

//     detailTable.importFromBinary(testFileName, &idMap);

//     ASSERT_TRUE(idMap.isEmpty()) << "ID map is empty after import.";

//     QVector<QVariantList> details = detailTable.dao.getAllDetailPersonalInfo();
//     ASSERT_GT(details.size(), 0) << "No details found after import.";
// }

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
