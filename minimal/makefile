##################################
# Edit these variables as needed #
##################################

# name of your executable
EXEC=hello

# locations
SRC_DIR=src
BUILD_DIR=build

# compiler
CXX=c++

# used to include headers. These will be passed to the compile proper stage
# Example:
#INCLUDES=-I/path/to/my-new-library/src -I/usr/local/likwid/include
INCLUDES=

# specify what flags to pass to the compile proper stage
COMPILE_FLAGS=-g -Wall -std=c++17

# used to tell the compiler to link a library.
# Example:
#LIBS=-llikwid -lfmt $(shell pkg-config --libs ncurses)
LIBS=

# used to tell the compiler extra locations to look for the libraries specified
# in $(LIBS). 
# Example:
#LIB_DIRS=-I/path/to/my-new-library/build -I/usr/local/likwid/lib
LIB_DIRS=

# pass any extra commands you want to send to the linking stage
LINK_FLAGS=

################################################
# Not intended to be edited, but I'm not a cop #
################################################

EXEC_DIR=$(BUILD_DIR)/bin
EXEC_FULL=$(EXEC_DIR)/$(EXEC)
OBJ_DIR=$(BUILD_DIR)/obj

build: $(EXEC_FULL)

all: build

run: $(EXEC_FULL)
	$(EXEC_FULL)

clean:
	rm $(OBJS) $(EXEC_FULL)

SRCS=$(wildcard $(SRC_DIR)/*.cpp)
OBJS=$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# sources depend on headers
$(SRC_DIR)/%.cpp: $(SRC_DIR)/%.hpp

# compilation dependencies
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(INCLUDES) $(COMPILE_FLAGS) -c $< -o $@

# executable dependencies
$(EXEC_FULL): $(OBJS) | $(EXEC_DIR)
	$(CXX) $(LIB_DIRS) $(LIBS) $(LINK_FLAGS) $(OBJS) -o $@

# make directories if needed:
define mkdir-command
mkdir -p $@
endef

$(EXEC_DIR):
	$(mkdir-command)

$(OBJ_DIR):
	$(mkdir-command)
