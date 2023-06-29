if(NOT DEFINED OpenCV_URL)
    if(WIN32)
        set(OpenCV_URL "https://github.com/OhMyAgnes/opencv-binary/releases/download/4.5.2/opencv-4.5.2-win-sdk.zip")
    else()
        set(OpenCV_URL "https://github.com/OhMyAgnes/opencv-binary/releases/download/4.5.2/opencv-4.5.2-linux.tar.gz")
    endif()
endif()

include(FetchContent)

FetchContent_Declare(OpenCV
    URL ${OpenCV_URL}
)

FetchContent_MakeAvailable(OpenCV)

FetchContent_GetProperties(OpenCV SOURCE_DIR OpenCV_SOURCE_DIR)

# get OpenCV_DIR
if(WIN32)
    set(OpenCV_DIR ${OpenCV_SOURCE_DIR}/x64/vc16/lib)
else()
    set(OpenCV_DIR ${OpenCV_SOURCE_DIR}/lib/cmake/opencv4)
endif()
