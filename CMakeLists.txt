cmake_minimum_required(VERSION 3.16)
project(agent VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# find_package(CURL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(SOURCES
        src/main.cpp
        src/transport/http_client.cpp
        src/collectors/metric_collector.cpp
)

add_executable(agent
        ${SOURCES}
)

# target_link_libraries(agent
#         CURL::libcurl
# )

if(MSVC)
    target_compile_options(agent PRIVATE /W4)
else()
    target_compile_options(agent PRIVATE -Wall -Wextra)
endif()