#include <pathfinder.h>

void mx_error_wrong_args_or_file(int argc, char *argv[], t_islands *path) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    path->fd = open(argv[1], O_RDONLY);
    path->file_in_str = NULL;
    if (path->fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        mx_clean_memory_path(path);
        exit(1);
    }
}
