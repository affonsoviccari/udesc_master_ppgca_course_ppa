FLAGS=-O3 -fopenmp
EXEC=knn
CC=gcc

ALL: $(EXEC)

$(EXEC):
	$(CC) $(FLAGS) quicksort_openmp.c -c -o quicksort_openmp.o
	$(CC) $(FLAGS) $(EXEC).c -c -o $(EXEC).o
	$(CC) $(FLAGS) $(EXEC).o quicksort_openmp.o -o $(EXEC)

clean:
	rm -rf $(EXEC) *.o
