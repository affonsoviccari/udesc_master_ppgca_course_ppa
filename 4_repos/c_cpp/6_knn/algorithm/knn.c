#include "knn.h"

char knn(int n_groups, Group * groups, int k, Point to_evaluate) {
    int i, j;

    for (i = 0; i < n_groups; i++) {
        Group g = groups[i];

        for (j = 0; j < g.length; j++) {
            float d = euclidean_distance_no_sqrt(to_evaluate, g.points[j]);
            g.distances[j] = d;
        }
    }

    int total_lenght = 0;
    for (i = 0; i < n_groups; i++){
        total_lenght += groups[i].length;
    }

    GroupDistLabel* all_groups_dist_label = malloc(sizeof(GroupDistLabel) * total_lenght);
    int x = 0;

    for (i = 0; i < n_groups; i++) {
        Group g = groups[i];
        for (j = 0; j < g.length; j++) {
            all_groups_dist_label[x].distance = g.distances[j];
            all_groups_dist_label[x].label = g.label;
            x++;
        }
    }

    for(i = 0; i < total_lenght; i++) {
        printf("%d ", all_groups_dist_label[i].distance);
    }

    quicksort_gdl(all_groups_dist_label, 0, (total_lenght - 1));

    char labels[k];
    for (i = 0; i < k; i++) {
        labels[i] = all_groups_dist_label[i].label;
    }
    

    char most_frequent = labels[0];
    int most_frequent_count = 1;
    int current_frequency = 1;

    for (i = 1; i < k; i++) {
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