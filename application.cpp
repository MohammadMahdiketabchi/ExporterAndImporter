#include "application.h"

Application::Application(const QString& mode): mode(mode) {}

void Application::execute()
{
    if (mode == "exporter") {
        Logger::instance().debug("run in export mode");
        exportAll();
    } else if (mode == "importer") {
        Logger::instance().debug("run in import mode");
        importAll();
    } else {
        Logger::instance().debug("invalid mode");
        qWarning() << "Invalid mode:" << mode;
    }
}

void Application::exportAll()
{
    exportTable(TableName::Group, "E:\\New Folder2\\ExxportAndImportV2\\_group.bin");
    exportTable(TableName::User, "E:\\New Folder2\\ExxportAndImportV2\\_user.bin");
    exportTable(TableName::DetailPersonalInfo,"E:\\New Folder2\\ExxportAndImportV2\\_detail_personal_info.bin");
}

void Application::importAll()
{
    importTable(TableName::Group,"E:\\New Folder2\\ExxportAndImportV2\\_group.bin", &groupIdMap);
    importTable(TableName::User,"E:\\New Folder2\\ExxportAndImportV2\\_user.bin", &userIdMap);
    importTable(TableName::DetailPersonalInfo,"E:\\New Folder2\\ExxportAndImportV2\\_detail_personal_info.bin", nullptr);
}

void Application::exportTable(TableName tableCode, const QString& fileName)
{
    auto table = TableFactory::createTable(tableCode, &groupIdMap, &userIdMap);
    if (!table) {
        Logger::instance().error("table not found");
        qWarning() << "Table not found";
        return;
    }
    table->exportToBinary(fileName);
}

void Application::importTable(TableName tableCode, const QString& fileName, QMap<int, int>* idMap)
{

    auto table = TableFactory::createTable(tableCode, &groupIdMap, &userIdMap);
    if (!table) {
        Logger::instance().error("table not found");
        qWarning() << "Table not found";
        return;
    }
    table->importFromBinary(fileName,idMap);
}
