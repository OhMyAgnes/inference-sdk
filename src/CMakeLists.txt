set(MODULE_NAME inference-sdk)

include(fetch/OpenCV)

find_package(OpenCV REQUIRED)

add_library(${MODULE_NAME} SHARED)


target_include_directories(${MODULE_NAME}
PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>
)

target_sources(${MODULE_NAME}
PRIVATE
    ./inference_module.cpp
)

target_link_libraries(${MODULE_NAME}
PUBLIC
    ${OpenCV_LIBS})

target_compile_definitions(${MODULE_NAME} PRIVATE DLL_EXPORT)