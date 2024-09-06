#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <libmx.h>

#define INT_MAX 2147483647

typedef struct s_islands {
    int fd;
    int words;
    int num_islands;
    char *file_in_str;
    char **uniq_isl;
    char **islands;
} t_islands;

typedef struct s_matrix {
    int len;
    int *route;
    long **first;
    long **table;
} t_matrix;

void mx_error_empty_file(char *argv[], t_islands *path);
void mx_error_wrong_args_or_file(int argc, char *argv[], t_islands *path);
void mx_error_invalid_line(t_islands *path);
void mx_error_num_of_islands(t_islands *path);
void mx_print_invalid_line(int line, t_islands *path);
void mx_error_bridges_len(t_islands *path);
void mx_matrix_init(t_islands *path, t_matrix *matrix);
void mx_floyd_warshall(t_islands *path, t_matrix *matrix);
void mx_print_result(void);
void mx_output_results(t_islands *path, t_matrix *matrix);
void mx_clean_memory_path(t_islands *path);
void mx_clean_memory_matrix(t_islands *path, t_matrix *matrix);

#endif
