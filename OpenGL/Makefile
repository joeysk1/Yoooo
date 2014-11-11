OBJS = main.o shader_manager.o verts.o matrix.o vector.o funcs.o

FRAMS = -framework Cocoa -framework OpenGL -framework CoreVideo -framework IOKit
LIBS = -lglfw3 -lglew -lm
CFLAGS = -std=c++0x -c
FLAGS = -std=c++0x

CC = g++

all:$(OBJS)
	$(CC) $(OBJS) $(FRAMS) $(LIBS) $(FLAGS) -o test

main.o:main.cpp
	$(CC) $(CFLAGS) main.cpp
shader_manager.o:./shader/shader_manager.h ./shader/shader_manager.cpp
	$(CC) $(CFLAGS) $(LIBS) ./shader/shader_manager.cpp -v
verts.o:./mesh/mesh.h ./mesh/include/verts.h ./mesh/src/verts.cpp
	$(CC) $(CFLAGS) ./mesh/src/verts.cpp
matrix.o:./math/math.h ./math/include/matrix.h ./math/src/matrix.cpp
	$(CC) $(CFLAGS) ./math/src/matrix.cpp
vector.o:./math/math.h ./math/include/vector.h ./math/src/vector.cpp
	$(CC) $(CFLAGS) ./math/src/vector.cpp
funcs.o:./math/math.h ./math/include/funcs.h ./math/src/funcs.cpp
	$(CC) $(CFLAGS) ./math/src/funcs.cpp

clean:
	rm *.o *~ test
