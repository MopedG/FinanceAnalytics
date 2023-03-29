#include "windowManager/windowmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::unique_ptr<WindowManager> manager = std::make_unique<WindowManager>();

    manager->startMainWindow();

    return a.exec();
}
