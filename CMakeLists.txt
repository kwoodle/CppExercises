cmake_minimum_required(VERSION 3.8)
project(CppExercises)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Peeps.h)
add_executable(CppExercises ${SOURCE_FILES})

find_package(Threads REQUIRED)
target_link_libraries(CppExercises Threads::Threads)

#set(BOOST_INCLUDEDIR "/usr/include")
find_package(Boost 1.64 COMPONENTS date_time system filesystem)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(Ex6_2 Ex6_2.cpp)
target_link_libraries(Ex6_2 Threads::Threads)

add_executable(Ex6_3 Ex6_3.cpp)
target_link_libraries(Ex6_3 ${Boost_LIBRARIES})

add_executable(Ex6_4 Ex6_4.cpp)
add_executable(Ex5_9 Ex5_9.cpp)
add_executable(Ex5_7 Ex5_7.cpp)

#add_executable(Sort Sort.cpp)