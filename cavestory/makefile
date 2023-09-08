#
# C++ makefile to build on windows and unix.
#
SRC = ./source
CLASSES = **/*.cpp
TARGET = ./build
RM = rm -rf
MKDIR = mkdir -p build

# C/C++ compiler program.
CC = g++


# Paths to include directories.
INCLUDE_PATHS = -I${SRC}/headers
INCLUDE_PATHS_WIN = -I/c/mingw_dev_lib/include/SDL2

# Paths to additional libraries.
LIBRARY_PATHS_WIN = -L/c/mingw_dev_lib/lib

# Compiler flags to pass to ${CC}.
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w
COMPILER_FLAGS_WIN = -Wl,-subsystem,windows

# Library flags to link.
LINKER_FLAGS = -lSDL2 -lSDL2main
LINKER_FLAGS_WIN = -lmingw32

# Output object name
OUT = cavestory
OUT_WIN = cavestory.exe

# Targets to clean, compile, and test the program.
compile:
	${MKDIR} && $(CC) ${SRC}/$(CLASSES) $(INCLUDE_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUT)

default: compile

clean:
	${RM} ${TARGET}

test: compile
	${TARGET}/${OUT}

all: clean default test

# Windows targets extending above Unix targets.
compile_win:
	$(CC) ${SRC}/$(CLASSES) $(INCLUDE_PATHS) $(INCLUDE_PATHS_WIN) $(LIBRARY_PATHS_WIN) $(COMPILER_FLAGS) $(COMPILER_FLAGS_WIN) $(LINKER_FLAGS) $(LINKER_FLAGS_WIN) -o $(TARGET)/$(OUT_WIN)

test_win: compile_win
	${TARGET}/${OUT_WIN}

all_win: compile_win test_win
