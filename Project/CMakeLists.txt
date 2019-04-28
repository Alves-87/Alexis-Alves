cmake_minimum_required(VERSION 3.8)

list(APPEND CMAKE_MODULE_PATH "
${CMAKE_CURRENT_SOURCE_DIR}/../cmake")



set(CMAKE_CXX_STANDARD 14)

set(TRON_LIST
   ${TRON_LIST}
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/game.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/base.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/items.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/graphics.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/game.h
   ${CMAKE_CURRENT_SOURCE_DIR}/base.h
   ${CMAKE_CURRENT_SOURCE_DIR}/items.h
   ${CMAKE_CURRENT_SOURCE_DIR}/graphics.cpp
   )

find_package(SFML COMPONENTS graphics window system)

include_directories(${SFML_INCLUDE_DIR})



add_executable(tron ${TRON_LIST})


target_link_libraries(tron ${SFML_LIBRARIES})