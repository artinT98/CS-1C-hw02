# Variables
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# Target executable
TARGET = hw02

# Source files
SRCS = hw02.cpp menu.cpp add_record.cpp delete_record.cpp display_record.cpp save_and_exit.cpp sort_by_name.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp hw02.h
	$(CXX) $(CXXFLAGS) -c $<

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Create a tarball of all project files
tar: clean
	tar -cvf hw02.tar *.cpp *.h makefile studentdb.txt