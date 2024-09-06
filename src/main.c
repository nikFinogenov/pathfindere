#include <pathfinder.h>

static void all_errors(int argc, char *argv[], t_islands *path) {
    mx_error_wrong_args_or_file(argc, argv, path);
    mx_error_empty_file(argv, path);
    mx_error_invalid_line(path);
    mx_error_num_of_islands(path);
    mx_error_bridges_len(path);
}

int main(int argc, char *argv[]) {
    t_islands *path = (t_islands *)malloc(sizeof(t_islands));
    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));

    all_errors(argc, argv, path);
    mx_matrix_init(path, matrix);
    mx_floyd_warshall(path, matrix);
    mx_output_results(path, matrix);
    mx_del_strarr(&path->uniq_isl);
    mx_del_strarr(&path->islands);
    mx_clean_memory_matrix(path, matrix);
    mx_clean_memory_path(path);
    return 0;
}
