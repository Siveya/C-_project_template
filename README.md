# 🚀 现代 C++ 项目模板

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)

## 📖 项目介绍
这是一个现代、功能完整的 C++ 项目模板，集成了业界最佳实践和现代开发工具链。适合快速启动新的 C++ 项目。

## ✨ 核心特性

### 🔧 构建系统
- **现代 CMake 3.12+** - 支持最新的 CMake 特性
- **多平台支持** - Linux、Windows、macOS

### 🧪 测试和质量保证
- **单元测试** - Google Test 框架

### 🚀 DevOps 和 CI/CD
- **GitHub Actions** - 自动化构建、测试、部署
- **多编译器支持** - GCC、Clang、MSVC

### 🎨 开发体验
- **VS Code 集成** - 完整的开发环境配置
- **代码格式化** - clang-format 统一代码风格
- **Git Hook** - 自动化代码检查

## 项目结构
```shell
VSCode_Cpp_Configuration/
├── .vscode/                    # VS Code 配置
│   ├── c_cpp_properties.json   # C/C++ 配置
│   ├── launch.json            # 调试配置
│   ├── settings.json          # 编辑器设置
│   └── tasks.json             # 任务配置
├── include/                    # 公共头文件
│   ├── module1/             # 模块1的公共头文件
│   ├── module2/             # 模块2的公共头文件
│   ├── export.h             # 导出宏定义
│   └── version.h.in         # 版本信息模板
├── src/                       # 源代码
│   ├── module1/              # 模块1实现
│   ├── module2/              # 模块2实现
│   └── main.cpp              # 主程序
├── tests/                    # 单元测试
│   ├── main_test.cpp        # 测试主程序
│   ├── module1_test.cpp     # 模块1测试
│   ├── module2_test.cpp     # 模块2测试
│   └── CMakeLists.txt       # 测试构建配置
├── resource/                   # 资源文件
│   ├── config/                 # 配置文件
│   ├── images/                 # 图片文件
│   ├── sounds/                 # 音效文件
│   └── locales/                # 翻译文件
├── examples/                 # 示例代码
│   ├── basic_usage.cpp      # 基本用法示例
│   └── CMakeLists.txt       # 示例构建配置
├── build/                    # 构建输出目录
├── docs/                    # 文档
├── scripts/                  # 工具脚本
├── third_party/              # 第三方依赖
│   ├── googletest/           # Google Test 源码 用于单元测试
│   └── library2/
├── CMakeLists.txt         # 主构建文件
├── .clang-format          # 代码格式化配置
├── .gitignore            # Git 忽略配置
├── .gitmodules          # Git 子模块配置
├── LICENSE              # 许可证
└── README.md           # 本文件
```

## 构建要求
- CMake 3.12 或更高版本
- 支持 C++17 的编译器
- Git（用于获取依赖）

## 🚀 快速开始

### 方式一：使用构建脚本（推荐）

```bash
# 1. 克隆仓库
git clone https://github.com/Siveya/VSCode_Cpp_Configuration.git
cd VSCode_Cpp_Configuration
git submodule update --init --recursive

# 2. 使用构建脚本
chmod +x scripts/build.sh
./scripts/build.sh --help  # 查看所有选项

# 3. 默认构建
./scripts/build.sh

# 4. 开发构建（包含调试信息和代码覆盖率）
./scripts/build.sh -d -c -s
```

### 方式二：手动构建

```bash
# 1. 克隆仓库
git clone https://github.com/Siveya/VSCode_Cpp_Configuration.git
cd VSCode_Cpp_Configuration
git submodule update --init --recursive

# 2. 配置和构建
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)

# 3. 运行测试
ctest --output-on-failure

# 4. 运行示例
./examples/basic_usage
```

## 配置选项
在 CMake 配置时可以使用以下选项：
- `TEMPLATE_BUILD_TESTS`: 构建单元测试 (默认: ON)
- `TEMPLATE_BUILD_EXAMPLES`: 构建示例 (默认: ON)
- `TEMPLATE_ENABLE_WARNINGS`: 启用警告 (默认: ON)

示例：
```bash
cmake -DTEMPLATE_BUILD_TESTS=OFF -DTEMPLATE_BUILD_EXAMPLES=ON ..
```


## 许可证
[许可证名称] - 查看 [LICENSE](LICENSE) 文件了解详情。
