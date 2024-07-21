// #include <gtest/gtest.h>
// #include "Group_table.h"
// #include <QFile>
// #include <QDir>

// class GroupTableTest : public ::testing::Test {
// protected:
//     void SetUp() override {
//         testFileName = "test_group_table.dat";

//         GroupTable groupTable;
//         QMap<int, int> idMap;
//         groupTable.exportToBinary(testFileName);
//     }

//     void TearDown() override {
//         QFile::remove(testFileName);
//     }

//     QString testFileName;
// };

// TEST_F(GroupTableTest, ExportToBinary) {
//     GroupTable groupTable;
//     QString exportFileName = "export_test_group_table.dat";

//     groupTable.exportToBinary(exportFileName);

//     QFile file(exportFileName);
//     ASSERT_TRUE(file.exists()) << "Export file does not exist.";
//     ASSERT_GT(file.size(), 0) << "Export file is empty.";

//     file.remove();
// }

// TEST_F(GroupTableTest, ImportFromBinary) {
//     GroupTable groupTable;
//     QMap<int, int> idMap;

//     groupTable.importFromBinary(testFileName, &idMap);

//     ASSERT_FALSE(idMap.isEmpty()) << "ID map is empty after import.";

//     QVector<QVariantList> groups = groupTable.dao.getAllGroup();
//     ASSERT_GT(groups.size(), 0) << "No groups found after import.";
// }

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
