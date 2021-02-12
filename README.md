# YACS - Yet Another C++ Starter

Uses Catch2 for testing. Choose between conan/CMake or GNU make for builds.

# Motivation

There are many high-quality C++ boilerplates in existence already. However, I
have a couple reasons for wanting to build my own. First, I don't want to
learn CMake (yet). And also, I think I'll be happier if things are set up
just the way I like.

# Goals

- Easy. "Just Works", even when adding dependencies.
- Simple, understandable code.
- Testing is built-in.
- Educational: well-commented and able to teach someone new to build systems

# Boilerplate Types, Quickstart

This repository contains two folders, `full-build-system` and `minimal`. Each
contains one style of boilerplate, which will be explained below.

If you're anxious to get started, copy either one of those directories to
somewhere on your computer and start coding. For more information on each, read
on.

# Minimal

The goal of this boilerplate is to provide the simplest possible build solution
while still providing basic features. It is intended to be used for PoCs,
experiments, or projects that have few dependencies.

## Features:

- Only re-compiles changed files
- If a header file is changed, the associated source file is recompiled
- Fairly modular and DRY
- Some sensible default command line options are included
- No dependencies except a C++ compiler (however, `-std=c++17` is enabled by
  default)

This folder contains only a makefile, a `src` folder, and a `build` folder. The
`src` folder contains a hello world written across multiple files, and the
`build` folder is where objects and the executable will be created.

All source files should be created in the `src` folder. To change
the name of the executable or add library flags and locations, edit the
variables at the very top of the makefile. However, if many dependencies are
needed, consider using the more complete build system outlined below.

## Prerequisistes:

- GNU Make
- A C++ compiler

Install both of these with your package manager. On ubuntu you can do this 
with `sudo apt install build-essential`

## Usage:

### Running

To run this boilerplate, simply `cd` into the directory `minimal`, run `make`,
and then run `build/bin/hello`. Alternatively, run `make run` to build and run
in one step.

### Adding Dependencies

The general procedure is as follows:

1. Install your dependency. Whatever way you do this (package manager, build
   from source, etc.) make sure you find where it is installed.
2. In the makefile, add `-l<library-name>` to the variable `EXT_LIBS`
3. Next, add `-I/path/to/library/headers` to the variable `INCLUDES`
4. At this point, try to run your program with `make run`, as this may be all
   you need. If your code can now use the new library, you're done. Otherwise
   move on to the next step.
5. In the makefile, add `-L/path/to/library/libfiles` to the variable
   `EXT_LIB_DIRS`. This is not always necessary, as libraries installed with the
   package manager usually get placed in a path that the compiler already
   searches. However, this is necessary if, for instance, you build something
   from source and install it to a custom location.

This procedure can be made much easier by using the program `pkg-config`. It
automatically finds the location of many libraries and generates the flags
needed to pass to the compiler. For instance, suppose you just installed
`libcrypto`. To find the flags you need with `pkg-config`, follow these
instructions:

1. Run `pkg-config --libs-only-l libcrypto`. The output of this command is what
   you need to add to `EXT_LIBS` in the makefile.
2. Run `pkg-config --libs-only-L libcrypto` (note the capital `L`). The output
   of this command is what you need to add to `EXT_LIBS_DIRS` in the makefile.
   This output might be empty. If so, do nothing to `EXT_LIBS_DIRS`.
3. Run `pkg-config --cflags libcrypto`. The output of this command is what you
   need to add to `INCLUDES` in the makefile. This output might be empty. If so,
   do nothing to `INCLUDES`.

### Testing

In order for testing to work, we assume you have
[Catch2](https://github.com/catchorg/Catch2) installed. Use your package
manager to find this, e.g. `apt search catch2`, `dnf search catch2`,
`zypper se catch2`, etc.

After that, try running `make tests`, as it might work out of the box. If you
get the output "All tests passed" or similar, it worked! Otherwise, continue
below.

Then, make sure the variable `CATCH_INCLUDE` in the makefile points to the
location where your package manager installed catch (this is probably
`/usr/include/catch2` or similar). If you can't find it, try using `find` or
look for a way to get your package manager to tell you the details of where it
installed catch. Then you can edit `CATCH_INCLUDE` to point to that directory.

Once that's done, `make tests` should definitely work.

# Full Build System

This folder uses Conan for dependency resolution and build management. All
features are available from the command line, but it also integrates nicely
with JetBrains's CLion IDE if you install the conan plugin.

## Prerequisites:

- CMake (install with your distro's package manager: `sudo apt install cmake`
  or similar)
- [conan](https://docs.conan.io/en/latest/installation.html). 

## Features:

- Only recompiles what is changed
- Very easy to use, no messing with `CMakeList.txt` or `makefile` files.
- Dependencies are easy with package management by conan

All sources are in the `src` directory. No build directory exists by default,
but I recommend (and the `.gitignore` expects) you to name it 'build'. If you
add source files, add their names to the variable `sourcesList` in the file
`CMakeLists.txt`. There you may also change the name of your project or
executable.

The real beauty of Conan is how easy it is to add dependencies. You don't have
to worry about where they're stored or dependencies-of-dependencies. You simply
add whatever library you want to `conanfile.txt` and conan will automatically
grab it and its transitive dependencies.

## Usage:

### Running

To run your program, first make a `build` directory and switch to it:
`mkdir build && cd build`. Next, run the following commands in that build
directory:

1. `conan install ..`
2. `cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release`
3. `cmake --build .`

After that, run your program with `bin/hello`.

Once you've run each of those commands once, you can rebuild your program by
only running `cmake --build .` in your project build directory, as long as your
dependencies haven't changed.

### Adding Dependencies

To add dependencies, do the following:

1. Search for your package on [conan center](https://conan.io/center/). If it
   isn't there, you'll have to figure something else out. Maybe search for
   'conan <your package>' on the web. You may have to use another build system.
2. Assuming you found your package, copy the name and version (ex.
   `openssl/1.1.1i`) to your clipboard
3. Paste that string on a new line in the `[requires]` section of
   `conanfile.txt`
4. Re-run all build steps described above.

### Testing

When following the instructions described in the section 'Running', both the
main executable and the testing executable are generated. Simply run 
`bin/hello-test` from the build directory.
