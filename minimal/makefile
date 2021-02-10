##################################
# Edit these variables as needed #
##################################

# The main rules you will use are "all", "run", and "test"
# - `make all` (or just `make`): builds the program
# - `make run`: builds and runs the program
# - `make test`: runs unit tests with Catch

# name of your executable
EXEC=hello

# Locations
# must only contain the file with your `main` function
SRC_DIR=src
# all other code goes here
LIB_DIR=lib
BUILD_DIR=build

# compiler
CXX=c++

# used to include headers. These will be passed to the compile proper stage
# Example:
#INCLUDES=-I/path/to/my-new-library/src -I/usr/local/likwid/include
INCLUDES=

# specify what flags to pass to the compile proper stage
COMPILE_FLAGS=-g -Wall -std=c++17

# NOTE: this set of compile flags is provided for compatibility. If you have
# problems, first try uncommenting the line below:
#COMPILE_FLAGS=-g -Wall

# used to tell the compiler to link a library.
# Example:
#EXT_LIBS=-llikwid -lfmt $(shell pkg-config --libs ncurses)
EXT_LIBS=

# used to tell the compiler extra locations to look for the libraries specified
# in $(LIBS). 
# Example:
#EXT_LIB_DIRS=-I/path/to/my-new-library/build -I/usr/local/likwid/lib
EXT_LIB_DIRS=

# pass any extra commands you want to send to the linking stage
LINK_FLAGS=

################################################
# Not intended to be edited, but I'm not a cop #
################################################

EXEC_DIR=$(BUILD_DIR)/bin
EXEC_FULL=$(EXEC_DIR)/$(EXEC)
OBJ_DIR=$(BUILD_DIR)/obj

debug:
	@echo "SRCS: $(SRCS)"
	@echo "OBJS: $(OBJS)"

all: $(EXEC_FULL)

run: $(EXEC_FULL)
	$(EXEC_FULL)

clean:
	rm $(OBJS) $(EXEC_FULL)

SRCS=$(wildcard $(SRC_DIR)/*.cpp) 
LIBS=$(wildcard $(LIB_DIR)/*.cpp)
LIB_OBJS=$(LIBS:$(LIB_DIR)/%.cpp=$(OBJ_DIR)/%.o)
SRC_OBJ=$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o) 
OBJS=$(LIB_OBJS) $(SRC_OBJ)

# compile command
COMPILE_COMMAND=$(CXX) $(INCLUDES) -I./lib $(COMPILE_FLAGS) -c $< -o $@

# COMPILE
# for 'lib', catch changes to source or header
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.cpp $(LIB_DIR)/%.hpp | $(OBJ_DIR)
	$(COMPILE_COMMAND)

# COMPILE
# then, for 'src', catch changes to sources only
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(COMPILE_COMMAND)

# LINK
# executable dependencies
$(EXEC_FULL): $(OBJS) | $(EXEC_DIR)
	$(CXX) $(EXT_LIB_DIRS) $(EXT_LIBS) $(LINK_FLAGS) $^ -o $@

# make directories if needed:
define mkdir-command
mkdir -p $@
endef

$(EXEC_DIR):
	$(mkdir-command)

$(OBJ_DIR):
	$(mkdir-command)
