# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Executable name
TARGET = main

# All .cpp files in the folder
SRCS = $(wildcard app/*.cpp)
OBJS = $(SRCS:app/%.cpp=build/%.o)

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o into build/ folder
build/%.o: app/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if it doesn’t exist
build:
	mkdir -p build

# Clean
clean:
	rm -rf build $(TARGET)