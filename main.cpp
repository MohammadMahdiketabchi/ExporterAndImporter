#include <QCoreApplication>
#include "application.h"
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc < 2) {
        qWarning() << "Usage: " << argv[0] << " <mode>";
        return -1;
    }
    QString mode = argv[1];
    Application app(mode);
    app.execute();

    return 0;
}
