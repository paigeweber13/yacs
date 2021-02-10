##################################
# Edit these variables as needed #
##################################

#
# Basic Info
#
# This file may seem long, but the majority of it is comments. If you'd like to
# extend this file or learn more about GNU make, please do read it.
#
# The main rules you will use are "all", "run", "clean", and "test"
#  - `make all` (or just `make`): builds the program
#  - `make run`: builds and runs the program
#  - `make clean`: delete object files and executable, so that you can
#    						  completely re-build
#  - `make test`: runs unit tests with Catch. Be sure to include the catch
#    					    headers by editing the `INCLUDES` variable below
#


#
# Build Settings
#
# These are variables affecting compilation and linking that are commonly
# changed. Each is provided with a short explanation
#

# name of your executable
EXEC=hello
# compiler
CXX=c++

# specify what flags to pass to the compile proper stage
# NOTE: this set of compile flags is provided for compatibility. If you have
# problems, first try replacing `COMPILE_FLAGS` with the commented line below
#COMPILE_FLAGS=-g -Wall
COMPILE_FLAGS=-g -Wall -std=c++17

# pass any extra commands you want to send to the linking stage
LINK_FLAGS=


#
# Locations
#
# These are where you store different types of files. There isn't really a
# reason to change them, but if you do be sure to move your files to the
# location you specify.
#

# must only contain the file with your `main` function
SRC_DIR=src
# all other code goes here
LIB_DIR=lib
# where your object files and executable will go
BUILD_DIR=build
# where tests go
TEST_DIR=tests


#
# Includes
#
# This, combined with the section "external libraries", is used to add any
# third-party code you may want to use. 
#
# These flags tell the compiler about other locations we want to look for
# headers.
#
# Each location must be prefixed by '-I'
#
# Example: 
#INCLUDES=-I/path/to/my-new-library/src -I/usr/local/likwid/include
INCLUDES=

# Just like 'INCLUDES', but only for catch, so that we can include it only when
# needed.
# 
# IMPORTANT: if you want to use unit tests (`make test`), be sure to edit
# 'CATCH_INCLUDES' to the path where you have installed the catch headers.
CATCH_INCLUDE=-I/usr/include/catch2


#
# External Libraries
#
#	While "INCLUDES" tells the compiler about header files, "EXT_LIBS" and
# "EXT_LIB_DIRS" are used to tell the linker where the libraries are stored.
# Both are necessary to use third-party code.
#
# Each location must be prefixed by '-L'. These will be passed to the linker.
# 

# used to tell the compiler that we want to link a library.
# Example:
#EXT_LIBS=-llikwid -lfmt $(shell pkg-config --libs ncurses)
EXT_LIBS=

# used to tell the compiler extra locations to look for the libraries specified
# in $(LIBS). 
# Example:
#EXT_LIB_DIRS=-I/path/to/my-new-library/build -I/usr/local/likwid/lib
EXT_LIB_DIRS=


################################################
# Not intended to be edited, but I'm not a cop #
################################################

EXEC_DIR=$(BUILD_DIR)/bin
EXEC_FULL=$(EXEC_DIR)/$(EXEC)
OBJ_DIR=$(BUILD_DIR)/obj
TEST_EXEC_FULL=$(EXEC_DIR)/$(EXEC)-tests

all: $(EXEC_FULL)

run: $(EXEC_FULL)
	$(EXEC_FULL)

clean:
	rm $(SRC_OBJ) $(LIB_OBJS) $(TEST_OBJS) $(EXEC_FULL) $(TEST_EXEC_FULL)

test: $(TEST_EXEC_FULL)
	$(TEST_EXEC_FULL)

SRCS=$(wildcard $(SRC_DIR)/*.cpp) 
LIBS=$(wildcard $(LIB_DIR)/*.cpp)
TESTS=$(wildcard $(TEST_DIR)/*.cpp)
LIB_OBJS=$(LIBS:$(LIB_DIR)/%.cpp=$(OBJ_DIR)/%.o)
SRC_OBJ=$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o) 
TEST_OBJS=$(TESTS:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.o) 


################
# COMPILATION #
################

# compile command
COMPILE_COMMAND=$(CXX) $(INCLUDES) -I./lib $(COMPILE_FLAGS) -c $< -o $@

# for 'lib', catch changes to source or header
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.cpp $(LIB_DIR)/%.hpp | $(OBJ_DIR)
	$(COMPILE_COMMAND)

# then, for 'src', catch changes to sources only
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(COMPILE_COMMAND)

# for 'tests', also catch changes to sources only. Include catch!
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(INCLUDES) $(CATCH_INCLUDE) -I./lib $(COMPILE_FLAGS) -c $< -o $@


###########
# LINKING #
###########

# link command
LINK_COMMAND=$(CXX) $(EXT_LIB_DIRS) $(EXT_LIBS) $(LINK_FLAGS) $^ -o $@

# build the executable
$(EXEC_FULL): $(SRC_OBJ) $(LIB_OBJS) | $(EXEC_DIR)
	$(LINK_COMMAND)

# build the testing executable
$(TEST_EXEC_FULL): $(LIB_OBJS) $(TEST_OBJS) | $(EXEC_DIR)
	$(LINK_COMMAND)


# make directories if needed:
mkdir-command=mkdir -p $@

$(EXEC_DIR):
	$(mkdir-command)

$(OBJ_DIR):
	$(mkdir-command)
