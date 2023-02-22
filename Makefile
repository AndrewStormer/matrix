CC=gcc
CFLAGS=-Wall -Werror -I.
all: matrixalgorithms

matrixalgorithms : main.o matrixfuncs.o ludecomposition.o cholesky.o
	@echo Linking...
	$(CC) $(CFLAGS) -o matrixalgorithms main.o matrixfuncs.o ludecomposition.o cholesky.o -lm
	@echo Done!

main.o: main.c ludecomposition.h
	@echo Compiling...
	$(CC) $(CFLAGS) -c main.c

matrixfuncs.o : matrixfuncs.c matrixfuncs.h
	@echo Compiling...
	$(CC) $(CFLAGS) -c matrixfuncs.c

ludecomposition.o : ludecomposition.c ludecomposition.h
	@echo Compiling...
	$(CC) $(CFLAGS) -c ludecomposition.c

cholesky.o : cholesky.c cholesky.h
	@echo Compiling...
	$(CC) $(CFLAGS) -c cholesky.c

clean:
	$(RM) matrixalgorithms *.o *~
	@echo All clean!
