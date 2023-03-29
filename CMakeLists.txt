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
        ui/addEntry/addEntryWindow/addentrywindow.h
        ui/addEntry/addEntryWindow/addentrywindow.cpp
        ui/addEntry/addEntryWindow/addentrywindow.ui
        ui/addEntry/addEntryForm/entryform.h
        ui/addEntry/addEntryForm/entryform.cpp
        ui/addEntry/addEntryForm/entryform.ui
        ui/addEntry/entryDatahandler/entrydatahandler.h
        ui/addEntry/entryDatahandler/entrydatahandler.cpp
        ui/addEntry/entryDatahandler/entrydata.h
        ui/addEntry/entryDatahandler/entrydata.cpp
        src/windowManager/windowmanager.h
        src/windowManager/windowmanager.cpp
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
