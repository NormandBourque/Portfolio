CC = g++
CFLAGS = -c -g -Og -Wall -Werror -ansi -pedantic -std=c++11
OBJ = Project2.o
DEPS = 
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXE = Project2

all: $(OBJ)
	$(clear)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)