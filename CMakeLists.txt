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

# Hypodermic
add_subdirectory(3rd_party/Hypodermic)

# Box2D
add_subdirectory(3rd_party/Box2D)

# YAML
add_subdirectory(3rd_party/YAML)

add_executable(${PROJECT_NAME} src/main.cpp src/Config.h.in src/Core/Logger/LoggerInterface.hpp src/Core/Logger/LogLevel.hpp src/Core/Logger/Logger.cpp src/Core/Logger/Logger.hpp src/Core/Logger/LogHandlerInterface.hpp src/Core/Logger/ConsoleLogHandler.cpp src/Core/Logger/ConsoleLogHandler.hpp src/Core/Logger/FileLogHandler.cpp src/Core/Logger/FileLogHandler.hpp src/Core/Format/TimeFormatInterface.hpp src/Core/Format/TimeFormat.cpp src/Core/Format/TimeFormat.hpp src/Core/Config/ConfigManagerInterface.hpp src/Core/Config/ConfigManager.cpp src/Core/Config/ConfigManager.hpp src/Core/Format/TimeFormatConfig.hpp src/Core/Logger/FileLogHandlerConfig.hpp src/Application/GameApp.cpp src/Application/GameApp.hpp src/Game/State/StateInterface.hpp src/Application/State/GameState.cpp src/Application/State/GameState.hpp src/Game/State/StateManagerInterface.hpp src/Game/State/StateManager.cpp src/Game/State/StateManager.hpp src/Core/Kernel/KernelInterface.hpp src/Core/Kernel/Kernel.cpp src/Core/Kernel/Kernel.hpp src/Application/AppKernel.cpp src/Application/AppKernel.hpp src/Game/Loop/LoopInterface.hpp src/Game/Loop/Loop.cpp src/Game/Loop/Loop.hpp src/Game/Loop/FramerateLimitedLoop.cpp src/Game/Loop/FramerateLimitedLoop.hpp src/Core/Time.cpp src/Core/Time.hpp src/Game/Loop/AdvancedLoop.cpp src/Game/Loop/AdvancedLoop.hpp src/Game/Loop/ExpertLoop.cpp src/Game/Loop/ExpertLoop.hpp)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-system sfml-window sfml-network tobanteGaming::Box2D Hypodermic yaml-cpp)
