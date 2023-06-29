set(DEMO_NAME inference-demo)
set(MODULE_NAME inference-sdk)

include(fetch/OpenCV)

find_package(OpenCV REQUIRED)

add_executable(${DEMO_NAME} main.cpp)

target_link_libraries(${DEMO_NAME}
PRIVATE 
    ${MODULE_NAME})
