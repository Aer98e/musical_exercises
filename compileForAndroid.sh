# Definir la ruta al NDK
export NDK_PATH=/home/aer98e/SDKs/android-sdk/ndk/30.0.16248370

# Definir la arquitectura a la que quieres apuntar (ej. arm64-v8a)
#export ABI=armeabi-v7a
#export ABI=arm64-v8a
export ABI=x86_64

# Generar los archivos de construcción con el Toolchain del NDK
cmake -B build_android_$ABI \
  -G "Unix Makefiles" \
  -DCMAKE_TOOLCHAIN_FILE=$NDK_PATH/build/cmake/android.toolchain.cmake \
  -DANDROID_ABI=$ABI \
  -DANDROID_PLATFORM=android-21 \
  -DCMAKE_BUILD_TYPE=Release

# Compilar la librería
cmake --build build_android_$ABI -- -j$(nproc)
