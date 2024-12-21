cmake_minimum_required(VERSION 3.25)
project(midday-commander)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
find_package(OpenSSL REQUIRED)

file(GLOB_RECURSE source CONFIGURE_DEPENDS
        "src/*.h"
        "src/*.cpp")

add_executable(midday-commander ${source})

target_link_libraries(midday-commander PRIVATE ${CURSES_LIBRARIES} OpenSSL::Crypto)
