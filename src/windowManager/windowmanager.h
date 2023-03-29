#pragma once
#include "mainWindow/mainwindow.h"
#include <QObject>

class WindowManager : public QObject
{
    Q_OBJECT
public:
    WindowManager();

    void startMainWindow();

private:
    MainWindow *mainWindow;

};

