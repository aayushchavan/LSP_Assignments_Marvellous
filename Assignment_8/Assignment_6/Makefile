CC = gcc

OBJ = add.o sub.o mul.o div.o
LIB = libmath.so

so:
	$(CC) -fPIC -c add.c sub.c mul.c div.c
	$(CC) -shared -o $(LIB) $(OBJ)

app: so
	$(CC) main.c -L. -lmath -o app

run:
	LD_LIBRARY_PATH=. ./app

clean:
	rm -f *.o *.so app
