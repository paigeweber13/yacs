# YACS - Yet Another C++ Starter

# Motivation

There are many high-quaity C++ boilerplates in existence already. However, I
have a couple reasons for wanting to build my own. First, I don't want to
learn CMake (yet). And also, I think I'll be happier if things are set up
just the way I like.

# Boilerplate Types

This repository contains two folders, `full-build-system` and `minimal`. Each
contains one style of boilerplate, which will be explained below.

# Minimal

The goal of this boilerplate is to provide the simplest possible build solution
while still providing basic features. It is intended to be used for PoCs,
experiments, or projects that have few dependencies.

Features:

- Only re-compiles changed files
- If a header file is changed, the associated source file is recompiled
- Fairly modular and DRY
- Some sensible default command line options are included
- No dependencies except a C++ compiler (however, `-std=c++17` is enabled by
  default)

This folder contains only a makefile, a `src` folder, and a `build` folder. The
`src` folder contains a hello world written across multiple files, and the
`build` folder is where objects and the executable will be created.

To run this boilerplate, simply `cd` into the directory `minimal`, run `make`,
and then run `build/bin/hello`. Alternatively, run `make run` to build and run
in one step. All source files should be created in the `src` folder. To change
the name of the executable or add library flags and locations, edit the
variables at the very top of the makefile. However, if many dependencies are
needed, consider using the more complete build system outlined below.

# Full Build System

This folder uses Conan for dependency resolution and build management.
