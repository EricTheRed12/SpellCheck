# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall -Werror -Wextra -Wpedantic -lstdc++fs

#no optimization for debugging (can be swapped)
DEBUG = -O0 -g
#optimization for execution
EXECUTE = -O3


#file paths
cPath = cpp_files
hPath = h_files
oPath = o_files
tPath = txt_files
xPath = exe_files

# the build target executable:
TARGET = $(xPath)/SpellCheck.exe

OBJECTS = $(addprefix $(oPath)/, TextReader.o)

buildd: $(OBJECTS) $(TARGET)

build:

objects: $(OBJECTS)

reader: $(oPath)/TextReader.o

clean:
		$(RM) $(oPath)/*.o $(xPath)/*.exe
run:
		./$(TARGET)

#rules
$(oPath)/%.o: $(cPath)/%.cpp
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

$(xPath)/%.exe: $(cPath)/%.cpp
	$(CC) $(CFLAGS) $(DEBUG) $< -o $@ $(OBJECTS)
