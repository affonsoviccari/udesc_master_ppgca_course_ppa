#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include "knn.h"

void swap(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}

void swap_gdl(GroupDistLabel* a, GroupDistLabel* b){
  GroupDistLabel t = *a;
  *a = *b;
  *b = t;
}

int particioning(int array[], int low, int high){
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++){
    if (array[j] < pivot){
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

int particioning_gdl(GroupDistLabel array[], int low, int high){
  float pivot = array[high].distance;
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++){
    if (array[j].distance < pivot){
      i++;
      swap_gdl(&array[i], &array[j]);
    }
  }
  swap_gdl(&array[i + 1], &array[high]);
  return (i + 1);
}

void quicksort(int array[], int low, int high) {
  if (low < high) {
    int pivot = particioning(array, low, high);

    #pragma omp task
    {
      quicksort(array, low, pivot - 1);
    }

    #pragma omp task
    {
      quicksort(array, pivot + 1, high);
    }
  }
}

void quicksort_gdl(GroupDistLabel array[], int low, int high) {
  /** Quicksort for GroupDistLabel */
  if (low < high) {
    int pivot = particioning_gdl(array, low, high);

    #pragma omp task
    {
      quicksort_gdl(array, low, pivot - 1);
    }

    #pragma omp task
    {
      quicksort_gdl(array, pivot + 1, high);
    }
  }
}