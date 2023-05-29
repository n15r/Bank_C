# Usage instructions

The package management feature of lcpkg is supported by vcpkg, and most packages are installed by vcpkg, so if you are using CMake, you can read the [vcpkg documentation](https://github.com/microsoft/vcpkg) to learn how to use these packages.

If you are not using CMake, please try the following methods.

## Visual Studio

Edit project properties and find the following configuration items:

- **C/C++ -> Additional Include Directories:** lcpkg\installed\$(PlatformTarget)-windows\include
- **Linker -> General -> Additinal Library Directories:** lcpkg\installed\$(PlatformTarget)-windows\lib
- **Linker -> Input -> Additinal Dependencies:** LCUI

## GCC

Add cflags and ldflags to compile:

    gcc -I lcpkg\installed\x64-linux\include -c example.c
    gcc -L lcpkg\installed\x64-linux\lib -lLCUI -o example example.o

## Other

Refer to the methods above to configure your build tools.
