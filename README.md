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
The goal of this boilerplate is to provide the simplest possible build 
solution, to be used for PoCs, experiments, or projects that have few 
dependencies.

This folder contains only a makefile, a `src` folder, and a `build` folder. The 
`src` folder contains a hello world written across multiple files, and the 
`build` folder is where objects and the executable will be created. The 
makefile compiles with some common options and will only recompile the 
necessary files.

To run this boilerplate, simply `cd` into the directory `minimal`, run `make`,
and then run `build/hello`. All source files should be created in the `src` 
folder. To change the name of the executable or add library flags and 
locations, edit the variables at the very top of the makefile. However, if 
many dependencies are needed, consider using the more complete build system 
outlined below.

# Full Build System
This folder uses Conan for dependency resolution and build management. 

