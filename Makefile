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

OBJECTS = $(addprefix $(oPath)/, TextReader.o Memory.o sqlite3)
HEADERS = $(addprefix $(hPath)/, TextReader.h Memory.h)

all: # keep for now
	make clean
	make buildd

buildd: $(OBJECTS) $(TARGET)

build:

sql: sqlite/sqlite3.c
	gcc -c -o $(oPath)/sqlite3 $^ -lpthread -ldl

clean:
		$(RM) $(oPath)/*.o $(xPath)/*.exe *.db
run:
		./$(TARGET)

#rules
$(oPath)/%.o: $(cPath)/%.cpp
	$(CC) $(CFLAGS) -c $<  -o $@

$(xPath)/%.exe: $(cPath)/%.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $(DEBUG) $< -o $@ $(OBJECTS) -lpthread -ldl
