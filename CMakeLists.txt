cmake_minimum_required(VERSION 3.10)

#set(CMAKE_CXX_STANDART 17)

project(PGoN)

option(TESTING "Start the test of the program" OFF)

set(SRC "${PROJECT_SOURCE_DIR}/src/main.cpp")

include_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/include
)

file(GLOB all_SRCS
	"${PROJECT_SOURCE_DIR}/include/*.h"
	"${PROJECT_SOURCE_DIR}/include/*.hpp"
	"${PROJECT_SOURCE_DIR}/include/entity/*.h"
	"${PROJECT_SOURCE_DIR}/include/entity/*.hpp"
	"${PROJECT_SOURCE_DIR}/src/*.c"
	"${PROJECT_SOURCE_DIR}/src/*.cpp"
)

link_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/include
)

add_executable(PGoN ${all_SRCS})
#add_executable(PGoN ${SRC})

target_link_libraries(
	PGoN
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/src
)

target_compile_features(PGoN PUBLIC cxx_std_17)

if(TESTING)
	add_compile_definitions(TESTING)
endif()
