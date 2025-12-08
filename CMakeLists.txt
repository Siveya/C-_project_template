# 指定构建项目所需的最低 CMake 版本
cmake_minimum_required(VERSION 3.12)

# 设置项目名称和版本
project(Template
    VERSION 1.0.1
    DESCRIPTION "An example of a modern C++ project"
    LANGUAGES CXX)

# 生成头文件 version.h
configure_file(
    ${CMAKE_SOURCE_DIR}/include/version.h.in
    ${CMAKE_BINARY_DIR}/include/version.h
)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 编译选项
option(TEMPLATE_BUILD_TESTS "Build tests" ON)
option(TEMPLATE_BUILD_EXAMPLES "Build examples" ON)
option(TEMPLATE_ENABLE_WARNINGS "Enable warnings" ON)

# 设置默认构建类型
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# 编译器警告
if(TEMPLATE_ENABLE_WARNINGS)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(-Wall -Wextra -Wpedantic -Werror)
    elseif(MSVC)
        add_compile_options(/W4 /WX)
    endif()
endif()

# MSVC 特定设置
if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MTd")
endif()

# 添加子目录
add_subdirectory(src)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>  # 构建时用
        $<INSTALL_INTERFACE:include>                   # 安装后用
)

# 创建可执行文件
add_executable(${PROJECT_NAME}_exe src/main.cpp)
target_link_libraries(${PROJECT_NAME}_exe PRIVATE ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME}_exe PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

if(TEMPLATE_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(TEMPLATE_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()


# 安装配置
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_exe
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# 导出配置
install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    FILES_MATCHING PATTERN "*.h" PATTERN "*.h"
)

# 生成并安装 CMake 配置文件
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
