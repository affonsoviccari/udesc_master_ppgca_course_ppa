
CXXFLAGS=-O3 -std=c++11 -Wall -pg -fopenmp
RM=rm -f
EXEC=mandelbrot

all: $(EXEC)

$(EXEC):
	$(CXX) $(CXXFLAGS) $(EXEC).cpp -c -o $(EXEC).o
	$(CXX) $(CXXFLAGS) $(EXEC).o -o $(EXEC)

profile:
	gprof $(EXEC) gmon.out > gmon.txt

clean:
	$(RM) $(EXEC).o $(EXEC) gmon.out gmon.txt
