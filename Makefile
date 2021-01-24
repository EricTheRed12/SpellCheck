# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall -Werror -Wextra -Wpedantic

#no optimization for debugging
DEBUG = -O0 -g
#optimization for execution
EXECUTE = -O3

# the build target executable:
TARGET = SpellCheck

#SpellCheck.o:
all: $(TARGET).o
	$(CC) $(CFLAGS) $(DEBUG) -o Executables/$(TARGET).exe $(TARGET).cpp

#debug
clean:
				$(RM) *.o *.exe
push:

run:
	./$(TARGET).exe
