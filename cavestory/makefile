#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = build/hello_world

#This is the target that compiles our executable
all : $(OBJS)
	mkdir build
	g++ $(OBJS) -w -lSDL2 -o $(OBJ_NAME)
