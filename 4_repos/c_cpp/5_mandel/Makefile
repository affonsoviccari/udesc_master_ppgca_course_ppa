
CXXFLAGS=-O3 -std=c++11 -Wall -pg -fopenmp
RM=rm -f
EXEC=mandelbrot

all: $(EXEC)

$(EXEC):
	$(CXX) $(CXXFLAGS) $(EXEC).cpp -c -o $(EXEC).o
	$(CXX) $(CXXFLAGS) $(EXEC).o -o $(EXEC)

run:
	for i in 1 2 3; do ./mandelbrot < mandelbrot.in; done

run_all:
	for k in 1 12; do \
		echo "=== num_threads=$$k ==="; \
		for j in 1 5 10 20 35 50 100 200 500 1000 2000 4000 8000 16000; do \
			echo "=== chunk_size=$$j ==="; \
			for i in 1 2 3; do ./mandelbrot $$j $$k < mandelbrot.in; done; \
		done; \
	done;


profile:
	gprof $(EXEC) gmon.out > gmon.txt

clean:
	$(RM) $(EXEC).o $(EXEC) gmon.out gmon.txt
