#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

matriz_t *matriz_criar(int linhas, int colunas)
{
	matriz_t *retorno = NULL;
	retorno = (matriz_t *) malloc(sizeof(matriz_t));
	retorno->linhas = linhas;
	(*retorno).colunas = colunas;

	double *temp = NULL;
	temp = (double *) malloc(linhas * colunas * sizeof(double));
	retorno->dados = (double **) malloc(linhas * sizeof(double *));

	int i;
	for (i = 0; i < linhas; i++) {
		retorno->dados[i] = &temp[i * colunas];
	}

    	return retorno;
}

void matriz_destruir(matriz_t *m)
{
	free(&m->dados[0][0]);
	free(m->dados);
	free(m);
	return;
}

void matriz_preencher_rand(matriz_t *m)
{
   int i, j;
   for (i = 0; i < m->linhas; i++) {
      for (j = 0; j < m->colunas; j++) {
         m->dados[i][j] = random();
      }
   }
}

void matriz_preencher(matriz_t *m, double valor)
{
   int i, j;
   for (i = 0; i < m->linhas; i++) {
      for (j = 0; j < m->colunas; j++) {
         m->dados[i][j] = valor;
      }
   }
}

matriz_t *matriz_multiplicar(matriz_t *A, matriz_t *B)
{
	int i, j, k;
	double valor;
	matriz_t *retorno = NULL;
	retorno = matriz_criar(A->linhas, B->colunas);
	for (i = 0; i < A->linhas; i++) {
		for (j = 0; j < B->colunas; j++) {
			valor = 0;
			for (k = 0; k < B->colunas; k++) {
				valor += A->dados[i][k] * B->dados[k][j];
			}
			retorno->dados[i][j] = valor;
		}
	}
	return retorno;
}

void matriz_imprimir(matriz_t *m)
{
   
   int i, j;
   for (i = 0; i < m->linhas; i++) {
      for (j = 0; j < m->colunas; j++) {
         printf("%.17f ", m->dados[i][j]);
      }
      printf("\n");
   }
}

matriz_t *matriz_somar(matriz_t *A, matriz_t *B)
{
	matriz_t *retorno = NULL;
	int i, j;
	retorno = matriz_criar(A->linhas, B->colunas);
	for (i = 0; i < A->linhas; i++) {
		for (j = 0; j < B->linhas; j++) {
			retorno->dados[i][j] = A->dados[i][j] + B->dados[i][j];
		}
	}

	return retorno;
}

