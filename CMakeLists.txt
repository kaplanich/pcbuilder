cmake_minimum_required(VERSION 3.5)

project(pcbuilder VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        src/main.cpp
        forms/mainwindow.cpp
        libs/mainwindow.h
        forms/mainwindow.ui
)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(pcbuilder
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        res.qrc
        libs/editandmore.h
        src/editandmore.cpp
        forms/buildtypeselection.h
        forms/buildtypeselection.cpp
        forms/buildtypeselection.ui
        libs/stackedbudgetbar.h
        src/stackedbudgetbar.cpp
        forms/buildeditdialog.h
        forms/buildeditdialog.cpp
        forms/buildeditdialog.ui
        libs/componenttile.h
        src/componenttile.cpp
        libs/graphiccard.h
        src/graphiccard.cpp
        libs/processor.h
        src/processor.cpp
        libs/ram.h
        src/ram.cpp
        libs/storage.h
        src/storage.cpp
        libs/case.h
        src/case.cpp
        libs/motherboard.h
        src/motherboard.cpp
        libs/coolingsystem.h
        src/coolingsystem.cpp
        libs/psu.h
        src/psu.cpp
        forms/addcomponentswindow.h
        forms/addcomponentswindow.cpp
        forms/addcomponentswindow.ui
        libs/componentwidget.h
        src/componentwidget.cpp
        libs/ComponentsLib.h
        libs/component.h
        src/component.cpp
        libs/componentfactory.h
        src/componentfactory.cpp
        libs/build.h
        src/build.cpp
        libs/componentlistwidget.h
        src/componentlistwidget.cpp
        libs/ImageCache.h
    )

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET pcbuilder APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(pcbuilder SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(pcbuilder
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(pcbuilder PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(pcbuilder PRIVATE Qt6::Sql)
target_link_libraries(pcbuilder PRIVATE Qt6::Core)
target_link_libraries(pcbuilder PRIVATE Qt6::Core)
target_link_libraries(pcbuilder PRIVATE Qt6::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.pcbuilder)
endif()
set_target_properties(pcbuilder PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include(GNUInstallDirs)
install(TARGETS pcbuilder
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(pcbuilder)
endif()
