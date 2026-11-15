cmake_minimum_required(VERSION 3.16)
project(cpp_opencv_homework CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# MSVC 默认按 GBK 读源码，中文注释/字符串会乱码报错，强制按 UTF-8
if(MSVC)
    add_compile_options("/utf-8")
endif()

# 本机 OpenCV 安装位置（预编译包解压后的 build 文件夹），别的机器改成自己的路径
set(OpenCV_DIR "D:/tools/opencv/build" CACHE PATH "OpenCV build 目录")
find_package(OpenCV REQUIRED)

add_executable(cpp_opencv_homework
    main.cpp
    inc/common.hpp
    inc/work1.hpp
    src/work1.cpp)

target_include_directories(cpp_opencv_homework PRIVATE inc ${OpenCV_INCLUDE_DIRS})
target_link_libraries(cpp_opencv_homework ${OpenCV_LIBS})

# 编译后把 opencv DLL 和测试图 sample.png 复制到 exe 旁，双击即可运行
add_custom_command(TARGET cpp_opencv_homework POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${OpenCV_DIR}/x64/vc16/bin/$<IF:$<CONFIG:Debug>,opencv_world4130d.dll,opencv_world4130.dll>"
        "$<TARGET_FILE_DIR:cpp_opencv_homework>"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/sample.png"
        "$<TARGET_FILE_DIR:cpp_opencv_homework>"
    COMMENT "复制 opencv DLL 和 sample.png 到 exe 目录")
