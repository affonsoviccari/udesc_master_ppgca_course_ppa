#include <complex>
#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char* argv[]){
	int chunk_size = (argc > 1) ? atoi(argv[1]) : 1;
	int n_threads = (argc > 2) ? atoi(argv[2]) : 1;

	int max_row, max_column, max_n;
	cin >> max_row;
	cin >> max_column;
	cin >> max_n;

	char **mat = (char**)malloc(sizeof(char*)*max_row);

	for (int i=0; i<max_row;i++)
		mat[i]=(char*)malloc(sizeof(char)*max_column);


	double start  = omp_get_wtime();

	#pragma omp parallel for num_threads(n_threads) schedule(guided, chunk_size)
	for(int r = 0; r < max_row; ++r){
		for(int c = 0; c < max_column; ++c){
			complex<float> z;
			int n = 0;
			while(abs(z) < 2 && ++n < max_n)
				z = pow(z, 2) + decltype(z)(
					(float)c * 2 / max_column - 1.5,
					(float)r * 2 / max_row - 1
				);
			mat[r][c]=(n == max_n ? '#' : '.');
		}
		// cout << omp_get_num_threads() << "\n";
	}

	double end  = omp_get_wtime();
	cout << end - start << "\n";
/*
	for(int r = 0; r < max_row; ++r){
		for(int c = 0; c < max_column; ++c)
			std::cout << mat[r][c];
		cout << '\n';
	}	
*/
}