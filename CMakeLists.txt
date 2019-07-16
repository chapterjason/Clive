cmake_minimum_required(VERSION 3.14)
project(Clive)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif ()

set(CMAKE_CXX_STANDARD 17)

# Version
set(CLIVE_VERSION_MAJOR 0)
set(CLIVE_VERSION_MINOR 1)
set(CLIVE_VERSION_PATCH 0)
set(CLIVE_VERSION_EXTRA DEV)

set(EXECUTABLE_NAME ${PROJECT_NAME})
configure_file(
        "${PROJECT_SOURCE_DIR}/src/Config.h.in"
        "${PROJECT_BINARY_DIR}/src/Config.h"
)
include_directories("${PROJECT_BINARY_DIR}")

# SFML
set(BUILD_SHARED_LIBS FALSE)
add_subdirectory(3rd_party/SFML)
set(SFML_STATIC_LIBRARIES TRUE)

#find_package(SFML 2.5 COMPONENTS window system network graphics audio REQUIRED)

# Box2D
add_subdirectory(3rd_party/Box2D)


add_executable(${PROJECT_NAME} src/main.cpp src/Config.h.in src/Core/Logger/LoggerInterface.hpp src/Core/Logger/LogLevel.hpp src/Core/Logger/Logger.cpp src/Core/Logger/Logger.hpp src/Core/Logger/LogHandlerInterface.hpp src/Core/Logger/ConsoleLogHandler.cpp src/Core/Logger/ConsoleLogHandler.hpp src/Core/DepndencyInjection/Container.cpp src/Core/DepndencyInjection/Container.hpp)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-system sfml-window sfml-network tobanteGaming::Box2D)
