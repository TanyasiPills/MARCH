BUILD_TYPE=${1:-Debug}
BUILD_DIR=build/$BUILD_TYPE


[ ! -d "build/" ] && mkdir "build/"

[ ! -d "$BUILD_DIR" ] && mkdir "$BUILD_DIR"
cd "$BUILD_DIR" || exit 1

SRC_DIR="$(pwd)/../.." 

if [[ OS == "Windows_NT" ]]; then
    echo "Configuring for Visual Studio..."
    cmake -G "Visual Studio 17 2022" -A x64 "$SRC_DIR"
else
    echo "Configuring for Linux..."
    cmake "$SRC_DIR"
fi

if [ "$BUILD_TYPE" == "Debug" ]; then
    echo "Building debug..."
    cmake --build . --config Debug
elif [ "$BUILD_TYPE" == "Release" ]; then
    echo "Building release..."
    cmake --build . --config Release
else
    echo "Unknown build type: $BUILD_TYPE"
    exit 1
fi