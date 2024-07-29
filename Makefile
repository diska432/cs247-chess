# CXX=g++
# CXXFLAGS=-std=c++14 -Wall -g -w

# EXEC=chess
# CCFILES=$(shell find . -name "*.cc")
# OBJECTS=${CCFILES:.cc=.o}
# DEPENDS=${CCFILES:.cc=.d}

# ${EXEC}: ${OBJECTS}
# 	${CXX} ${OBJECTS} -o ${EXEC}

# clean:
# 	rm -rf ${OBJECTS} ${DEPENDS} ${EXEC}

# -include ${DEPENDS}

# Define the compiler and flags
CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -w

# Define the executable and source files
EXEC = chess
CCFILES = $(shell find . -name "*.cc")
OBJECTS = ${CCFILES:.cc=.o}
DEPENDS = ${CCFILES:.cc=.d}

# Define the X11 library path
X11_LIB_PATH = /opt/X11/lib
X11_INC_PATH = /opt/X11/include

# Build the executable
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -L$(X11_LIB_PATH) -lX11

# Rule to build object files from source files
%.o: %.cc
	${CXX} ${CXXFLAGS} -I$(X11_INC_PATH) -c $< -o $@

# Clean up generated files
clean:
	rm -rf ${OBJECTS} ${DEPENDS} ${EXEC}

# Include dependency files
-include ${DEPENDS}
