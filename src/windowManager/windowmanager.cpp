#include "windowmanager.h"

WindowManager::WindowManager() :
    mainWindow(new MainWindow)
{

}

void WindowManager::startMainWindow()
{
    mainWindow->show();
}
