# My New Project

A summary will go here.

# Prerequisistes

- GNU make
- A C++ compiler
- CMake
- [Conan](https://conan.io/) (pip3 install --user conan)
- (Optional) [Catch2](https://github.com/catchorg/Catch2)

# Running

First, build executables:

1. `mkdir build && cd build`
2. `conan install ..`
3. `cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release`
4. `cmake --build .`

Next, (assuming you are still in the `build` directory) run the software with
`bin/hello`. You may run tests with `bin/hello-test`. Catch2 must be installed
for tests to work.
