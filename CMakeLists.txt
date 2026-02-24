cmake_minimum_required(VERSION 3.19)
project(QtLinkUniversal LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# ADD THIS LINE HERE:
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui")

find_package(Qt6 REQUIRED COMPONENTS Widgets SerialPort)

qt_standard_project_setup()

qt_add_executable(QtLinkUniversal
    src/main.cpp
    src/mainwindow.cpp
    include/mainwindow.h
    ui/mainwindow.ui
)

target_link_libraries(QtLinkUniversal PRIVATE Qt6::Widgets Qt6::SerialPort)

# Also tell the compiler where to find your .h files
target_include_directories(QtLinkUniversal PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")