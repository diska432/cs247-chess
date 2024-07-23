# Define the compiler and the flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Define the output executable
EXEC = main

# Find all .cc files in the root directory
SRCS = $(wildcard *.cc)

# Generate object files for each .cc file
OBJS = $(SRCS:.cc=.o)

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cc files into object files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets to avoid conflicts with files of the same name
.PHONY: all clean
