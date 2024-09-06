#include <pathfinder.h>

void mx_error_bridges_len(t_islands *path) {
    char *buf = mx_strchr(path->file_in_str, ',');

    for (unsigned len = 0; buf; buf = mx_strchr(buf, ',')) {
        len += mx_atoi(++buf);
        if (len > INT_MAX) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            mx_del_strarr(&path->uniq_isl);
            mx_del_strarr(&path->islands);
            mx_clean_memory_path(path);
            exit(1);
        }
    }
}
