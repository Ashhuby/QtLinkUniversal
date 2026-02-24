cmake_minimum_required(VERSION 3.19)
project(QtLinkUniversal LANGUAGES CXX)

# Standard Qt Automation
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Find Libraries
find_package(Qt6 REQUIRED COMPONENTS Widgets SerialPort)

qt_standard_project_setup()

# Define the app and file locations
qt_add_executable(QtLinkUniversal
    src/main.cpp
    src/mainwindow.cpp
    include/mainwindow.h
    ui/mainwindow.ui
)

# Link Modules
target_link_libraries(QtLinkUniversal PRIVATE Qt6::Widgets Qt6::SerialPort)