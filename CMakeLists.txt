cmake_minimum_required(VERSION 3.25)

project(rayitapi)
set(CROW_FEATURES "ssl;compression")
file(GLOB SOURCES "src/*.cpp")

find_package(Crow)
add_executable(rayitapi ${SOURCES})
target_link_libraries(rayitapi PUBLIC Crow::Crow sqlite3)
