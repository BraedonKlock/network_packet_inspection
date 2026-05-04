cmake_minimum_required(VERSION 3.16)

project(PacketInspectionEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    	add_compile_options(/W4 /EHsc)
else()
    	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(PacketInspectionEngine
    	src/main.cpp
)

target_include_directories(PacketInspectionEngine PRIVATE
    	${CMAKE_CURRENT_SOURCE_DIR}/includes
)

target_link_libraries(PacketInspectionEngine PRIVATE
    	pcap
)
