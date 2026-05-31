#include <complex>
#include <iostream>
#include <mpi.h>
#include <stdlib.h>
#include <omp.h>

using namespace std;

int main(int argc, char *argv[]){
        int max_row, max_column, max_n;
        if (argc != 4) {
                printf("Informe max_row max_col max_n\n");
                return 0;
        }

        MPI_Init(&argc, &argv);
        max_row = atoi(argv[1]);
        max_column = atoi(argv[2]);
        max_n = atoi(argv[3]);
        printf("%d %d %d\n", max_row, max_column, max_n);

        int rank, size;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        printf("%d %d\n", rank, size);

        char **mat = NULL; // mestre
        char **trabalho = NULL; // todos
        char *bloco = NULL;
        if (rank == 0) { // mestre
                mat = (char**)malloc(sizeof(char*)*max_row);
                bloco = (char *)malloc(sizeof(char) * max_row * max_column);
                for (int i=0; i<max_row;i++)
                        mat[i]=&bloco[i * max_column];
        }
        // todos devem preparar a memoria de trabalho
        int chunk = max_row / size; // numero de linhas que cada um deve trabalhar
        trabalho = (char **)malloc(sizeof(char *) * chunk);
char *bloco_trabalho = (char *)malloc(sizeof(char) * chunk * max_column);
        for (int i=0; i<chunk;i++)
                trabalho[i] = &bloco_trabalho[i * max_column];
        // memoria pronta
        // todos devem trabalhar
        for(int r = 0; r < chunk; ++r){
                for(int c = 0; c < max_column; ++c){
                        complex<float> z;
                        int n = 0;
                        while(abs(z) < 2 && ++n < max_n)
                                z = pow(z, 2) + decltype(z)(
                                        (float)c * 2 / max_column - 1.5,
                                        (float)(r + rank * chunk) * 2 / max_row - 1
                                );
                        // trabalhadores devem escrever na memoria de trabalho
                        trabalho[r][c]=(n == max_n ? '#' : '.');
                }
        }
        // precisamos remontar a matriz no mestre
        MPI_Gather(&bloco_trabalho[0], chunk * max_column, MPI_CHAR, &bloco[0], chunk * max_column, MPI_CHAR, 0, MPI_COMM_WORLD);


        // precisamos tratar o resto
        // transformar o calculo em função e invocar com o resto

        if (rank == 0) {
                for(int r = 0; r < max_row; ++r){
                        for(int c = 0; c < max_column; ++c)
                                std::cout << mat[r][c];
                        cout << '\n';
                }
        }
        MPI_Finalize();
}
