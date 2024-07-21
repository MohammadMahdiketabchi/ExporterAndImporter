// #include <gtest/gtest.h>
// #include "dataaccessobject.h"

// TEST(DataAccessObjectTests, GetAllGroup) {
//     DataAccessObject& dao = DataAccessObject::instance();
//     QVector<QVariantList> result = dao.getAllGroup();
//     ASSERT_GE(result.size(), 0);
// }

// TEST(DataAccessObjectTests, InsertToGroup) {
//     DataAccessObject& dao = DataAccessObject::instance();
//     int id = dao.insertToGroup("TestGroup", "This is a test group", 1);
//     ASSERT_GT(id, 0);
// }

// TEST(DataAccessObjectTests, GetAllUser) {
//     DataAccessObject& dao = DataAccessObject::instance();
//     QVector<QVariantList> result = dao.getAllUser();
//     ASSERT_GE(result.size(), 0);
// }

// TEST(DataAccessObjectTests, InsertToUser) {
//     DataAccessObject& dao = DataAccessObject::instance();
//     int id = dao.insertToUser("TestUser", "127.0.0.1", "password", 1);
//     ASSERT_GT(id, 0);
// }

// TEST(DataAccessObjectTests, GetAllDetailPersonalInfo) {
//     DataAccessObject& dao = DataAccessObject::instance();
//     QVector<QVariantList> result = dao.getAllDetailPersonalInfo();
//     ASSERT_GE(result.size(), 0);
// }

// TEST(DataAccessObjectTests, InsertToDetailPersonalInfo) {
//     DataAccessObject& dao = DataAccessObject::instance();
//     int id = dao.insertToDetailPersonalInfo(1, "John", "Doe", "Office", "123456789", "001", "Address");
//     ASSERT_GT(id, 0);
// }

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
