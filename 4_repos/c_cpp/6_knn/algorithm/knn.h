#ifndef KNN_H
#define KNN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    char label;
    int length;
    Point * points;
    float * distances;
} Group;

typedef struct {
    float distance;
    char label;
} GroupDistLabel;

void on_error();
int parse_number_of_groups();
Point parse_point();
Group parse_next_group();
int parse_k();
float euclidean_distance_no_sqrt(Point a, Point b);
int compare_for_sort(const void *a, const void *b);

#endif