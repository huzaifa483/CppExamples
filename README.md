# CppExamples

A C++ application built with CMake. Dependencies are managed via [vcpkg](https://github.com/microsoft/vcpkg). Tested on Windows with MSVC.

## ✅ Prerequisites

- [CMake](https://cmake.org/download/)
- [vcpkg](https://github.com/microsoft/vcpkg)
- [Visual Studio 2022](https://visualstudio.microsoft.com/vs/) (Desktop C++ workload)

## 📦 Dependencies via vcpkg

Install vcpkg and required packages:

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat
vcpkg install spdlog:x64-windows-static


git clone <your-repo-url>
cd CppExamples
mkdir build

cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=C:/Users/<username>/vcpkg/scripts/buildsystems/vcpkg.cmake  -DVCPKG_TARGET_TRIPLET=x64-windows-static

cmake --build build --config Release

```

your exe will be in Release folder.
