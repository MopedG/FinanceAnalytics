cmake_minimum_required(VERSION 3.5)

project(FinanceAnalytics VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        ui/mainWindow/mainwindow.cpp
        ui/mainWindow/mainwindow.h
        ui/mainWindow/mainwindow.ui
        ui/EntryWindow/EntryWindow/addentrywindow.h
        ui/EntryWindow/EntryWindow/addentrywindow.cpp
        ui/EntryWindow/EntryWindow/addentrywindow.ui
        ui/EntryWindow/EntryForm/entryform.h
        ui/EntryWindow/EntryForm/entryform.cpp
        ui/EntryWindow/EntryForm/entryform.ui
        ui/EntryWindow/ErrorMessageBox/errormessagebox.h
        ui/EntryWindow/ErrorMessageBox/errormessagebox.cpp
        ui/EntryWindow/ErrorMessageBox/errormessagebox.ui
        ui/EntryWindow/EntryDatahandler/entrydatahandler.h
        ui/EntryWindow/EntryDatahandler/entrydatahandler.cpp
        ui/EntryWindow/EntryDatahandler/entrydata.h
        ui/EntryWindow/EntryDatahandler/entrydata.cpp
        ui/EntryWindow/EntryController/entrycontroller.h
        ui/EntryWindow/EntryController/entrycontroller.cpp
        ui/StatisticsWindow/MainWindow/statisticswindow.h
        ui/StatisticsWindow/MainWindow/statisticswindow.cpp
        ui/StatisticsWindow/MainWindow/statisticswindow.ui
        ui/StatisticsWindow/Forms/MonthCard/MonthCard.h
        ui/StatisticsWindow/Forms/MonthCard/MonthCard.cpp
        ui/StatisticsWindow/Forms/MonthCard/MonthCard.ui
        ui/StatisticsWindow/Forms/SpendingForm/spendingform.h
        ui/StatisticsWindow/Forms/SpendingForm/spendingform.cpp
        ui/StatisticsWindow/Forms/SpendingForm/spendingform.ui

        src/windowManager/windowmanager.h
        src/windowManager/windowmanager.cpp
        src/validator/validator.h
        src/validator/validator.cpp
        src/sorter/sorter.h
        src/sorter/sorter.cpp
        src/repository/repository.h
        src/repository/repository.cpp
        src/repository/datahandler/datahandler.h
        src/repository/datahandler/datahandler.cpp
        src/repository/writer/writer.h
        src/repository/writer/writer.cpp
        src/repository/reader/reader.h
        src/repository/reader/reader.cpp
        src/repository/refactorer/refactorer.h
        src/repository/refactorer/refactorer.cpp
        assets/recource.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(FinanceAnalytics
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET FinanceAnalytics APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(FinanceAnalytics SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FinanceAnalytics
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(FinanceAnalytics PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/ui"
)

set_target_properties(FinanceAnalytics PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS FinanceAnalytics
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FinanceAnalytics)
endif()
