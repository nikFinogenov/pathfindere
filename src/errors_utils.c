#include <pathfinder.h>

void mx_clean_memory_path(t_islands *path) {
    if (path->file_in_str)
        mx_strdel(&path->file_in_str);
    free(path);
}

void mx_print_invalid_line(int line, t_islands *path) {
    char *print = mx_itoa(line);

    mx_printerr("error: line ");
    mx_printerr(print);
    mx_printerr(" is not valid\n");
    mx_clean_memory_path(path);
    exit(1); 
}
