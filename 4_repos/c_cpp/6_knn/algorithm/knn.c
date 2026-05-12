#include <omp.h>
#include "knn.h"
#include "quicksort_openmp.h"

void on_error() {
    printf("Invalid input file.\n");
    exit(1);
}

int parse_number_of_groups() {
    int n;
    if (scanf(" n_groups=%d ", &n) != 1) on_error();
    return n;
}

Point parse_point() {
    float x, y;
    if (scanf(" (%f ,%f) ", &x, &y) != 2) on_error();
    Point point;
    point.x = x;
    point.y = y;
    return point;
}

Group parse_next_group() {
    char label;
    int length;
    if (scanf(" label=%c ", &label) != 1) on_error();
    if (scanf(" length=%d ", &length) != 1) on_error();
    Group group;
    group.label = label;
    group.length = length;
    group.points = (Point *) malloc(sizeof(Point) * length);
    group.distances = (float *) malloc(sizeof(float) * length);
    for (int i = 0; i < length; i++) {
        group.points[i] = parse_point();
        group.distances[i] = -1;
    }
    return group;
}

int parse_k() {
    int k;
    if (scanf(" k=%d ", &k) != 1) on_error();
    return k;
}

float euclidean_distance_no_sqrt(Point a, Point b) {
    return ((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y));
}

int compare_for_sort(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

char knn(int n_groups, Group * groups, int k, Point to_evaluate) {
    double start, end;

    start = omp_get_wtime();

    #pragma omp parallel for schedule(dynamic) num_threads(16)
    for (int i = 0; i < n_groups; i++) {
        Group g = groups[i];

        for (int j = 0; j < g.length; j++) {
            float d = euclidean_distance_no_sqrt(to_evaluate, g.points[j]);
            g.distances[j] = d;
        }
    }

	end  = omp_get_wtime();
	printf("distances: %f\n", (end-start));

    int total_lenght = 0;
    for (int i = 0; i < n_groups; i++){
        total_lenght += groups[i].length;
    }

    GroupDistLabel* all_groups_dist_label = malloc(sizeof(GroupDistLabel) * total_lenght);
    int x = 0;

    for (int i = 0; i < n_groups; i++) {
        Group g = groups[i];
        for (int j = 0; j < g.length; j++) {
            all_groups_dist_label[x].distance = g.distances[j];
            all_groups_dist_label[x].label = g.label;
            x++;
        }
    }

    // printf("No sort:\n");
    // for(i = 0; i < total_lenght; i++) {
    //     printf("%f ", all_groups_dist_label[i].distance);
    // }
    // printf("\n");

    start = omp_get_wtime();

    #pragma omp parallel num_threads(16)
    {
        #pragma omp single
        {
        quicksort_gdl(all_groups_dist_label, 0, (total_lenght - 1));
        }
    }

	end  = omp_get_wtime();
	printf("sorter: %f\n", (end-start));

    // printf("Sorted:\n");
    // for(i = 0; i < total_lenght; i++) {
    //     printf("%f ", all_groups_dist_label[i].distance);
    // }
    // printf("\n");

    char labels[k];
    for (int i = 0; i < k; i++) {
        labels[i] = all_groups_dist_label[i].label;
    }

    char most_frequent = labels[0];
    int most_frequent_count = 1;
    int current_frequency = 1;

    for (int i = 1; i < k; i++) {
        if (labels[i] != labels[i - 1]) {
            if (current_frequency > most_frequent_count) {
                most_frequent = labels[i - 1];
                most_frequent_count = current_frequency;
            }

            current_frequency = 1;
        } else {
            current_frequency++;
        }

        if (i == k - 1 && current_frequency > most_frequent_count) {
            most_frequent = labels[i - 1];
            most_frequent_count = current_frequency;
        }
    }

    return most_frequent;
}

int main() {
    int n_groups = parse_number_of_groups();
    
    Group * groups = (Group *) malloc(sizeof(Group) * n_groups);

    for (int i = 0; i < n_groups; i++) {
        groups[i] = parse_next_group();
    }

    int k = parse_k();

    Point to_evaluate = parse_point();

    printf("%c\n", knn(n_groups, groups, k, to_evaluate));
}