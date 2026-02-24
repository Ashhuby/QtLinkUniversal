cmake_minimum_required(VERSION 3.19)
project(QtLinkUniversal LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Search the ui folder for mainwindow.ui
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui")

# Find Widgets and SerialPort
find_package(Qt6 REQUIRED COMPONENTS Widgets SerialPort)

qt_standard_project_setup()

qt_add_executable(QtLinkUniversal
    src/main.cpp
    src/mainwindow.cpp
    include/mainwindow.h
    ui/mainwindow.ui
)

# Link the necessary libraries
target_link_libraries(QtLinkUniversal PRIVATE Qt6::Widgets Qt6::SerialPort)

# Include the headers folder
target_include_directories(QtLinkUniversal PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")