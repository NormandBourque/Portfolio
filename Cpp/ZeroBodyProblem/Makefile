CC = g++
CFLAGS = -c -g -Og -Wall -Werror -ansi -pedantic -std=c++11
OBJ = Body.o NBody.o
DEPS = 
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXE = NBody

all: $(OBJ)
	$(clear)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)