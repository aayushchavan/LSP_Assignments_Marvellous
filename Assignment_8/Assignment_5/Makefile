CC = gcc
AR = ar
CFLAGS = -Wall

OBJ = add.o sub.o mul.o div.o
LIB = libmath.a

lib: $(OBJ)
	$(AR) rcs $(LIB) $(OBJ)

clean:
	rm -f *.o *.a
