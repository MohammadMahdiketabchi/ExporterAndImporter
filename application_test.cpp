// #include <gtest/gtest.h>
// #include "application.h"
// #include <QFile>
// #include <QDir>

// class ApplicationTest : public ::testing::Test {
// protected:
//     void SetUp() override {
//         exportPath = "E:\\New Folder2\\ExxportAndImportV2\\";

//         QDir().mkpath(exportPath);

//         QFile::remove(exportPath + "_group.bin");
//         QFile::remove(exportPath + "_user.bin");
//         QFile::remove(exportPath + "_detail_personal_info.bin");
//     }

//     void TearDown() override {
//         QFile::remove(exportPath + "_group.bin");
//         QFile::remove(exportPath + "_user.bin");
//         QFile::remove(exportPath + "_detail_personal_info.bin");
//     }

//     QString exportPath;
// };

// TEST_F(ApplicationTest, ExportAll) {
//     Application app("exporter");
//     app.execute();

//     EXPECT_TRUE(QFile::exists(exportPath + "_group.bin"));
//     EXPECT_TRUE(QFile::exists(exportPath + "_user.bin"));
//     EXPECT_TRUE(QFile::exists(exportPath + "_detail_personal_info.bin"));

//     EXPECT_GT(QFile(exportPath + "_group.bin").size(), 0);
//     EXPECT_GT(QFile(exportPath + "_user.bin").size(), 0);
//     EXPECT_GT(QFile(exportPath + "_detail_personal_info.bin").size(), 0);
// }

// TEST_F(ApplicationTest, ImportAll) {
//     Application exportApp("exporter");
//     exportApp.execute();

//     Application importApp("importer");
//     importApp.execute();

//     QMap<int, int> groupIdMap;
//     QMap<int, int> userIdMap;
//     DetailPersonalInfoTable detailTable(&userIdMap);

//     QVector<QVariantList> details = detailTable.dao.getAllDetailPersonalInfo();
//     EXPECT_GT(details.size(), 0);
// }

// TEST_F(ApplicationTest, InvalidMode) {
//     Application app("invalid_mode");
//     testing::internal::CaptureStderr();
//     app.execute();
//     std::string output = testing::internal::GetCapturedStderr();
//     EXPECT_NE(output.find("Invalid mode"), std::string::npos);

// }

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
