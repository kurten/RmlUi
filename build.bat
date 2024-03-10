@echo off
@setlocal
@chcp 65001 >nul

cmake -B Build -S . -DENABLE_LOTTIE_PLUGIN=ON -DENABLE_SVG_PLUGIN=ON -DBUILD_SAMPLES=ON -DCMAKE_TOOLCHAIN_FILE="E:/workspace/vcpkg/scripts/buildsystems/vcpkg.cmake"

cmake --build Build

if "%exit_or_pause%"=="" pause
endlocal