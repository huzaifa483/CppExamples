cmake_minimum_required(VERSION 3.31)
project(CppExamples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SPDLOG_USE_STATIC_LIB ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")


# Find Boost (required for Boost.Asio)
find_package(Boost REQUIRED COMPONENTS system serialization)
find_package(spdlog REQUIRED)
# Add executable
add_executable(CppExamples
    src/main.cpp
)
# Link Boost
target_link_libraries(CppExamples PRIVATE
    Boost::system
    Boost::serialization
    spdlog::spdlog
)
