SRC = source/**/*.cpp
INCLUDE = source/headers
OUT = build/cavestory

#This is the target that compiles our executable
all : $(SRC)
	mkdir -p build
	g++ -o ${OUT} -I ${INCLUDE} ${SRC} -w -lSDL2
