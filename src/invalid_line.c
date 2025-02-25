#include <pathfinder.h>

static int second_line_check(t_islands *path, char *str, int *line, int i) {
    if (str[i] == '\n' && str[i + 1] == '\0')
        return ++i;
    for ( ; str[i] != '-'; i++)
        if (!mx_isalpha(str[i]))
            mx_print_invalid_line(*line, path);
    if (str[i] == '-' && (!mx_isalpha(str[i - 1]) || !mx_isalpha(str[i + 1])))
        mx_print_invalid_line(*line, path);
    for (i++ ; str[i++ + 1] != ','; )
        if (!mx_isalpha(str[i]))
            mx_print_invalid_line(*line, path);
    if (str[i] == ',' && (!mx_isalpha(str[i - 1]) || !mx_isdigit(str[i + 1])))
        mx_print_invalid_line(*line, path);
    for (i++ ; str[i] != '\n'; i++)
        if (!mx_isdigit(str[i]) || (INT_MAX < mx_atoi(&(str[i])))) 
            mx_print_invalid_line(*line, path);
    if (str[i] != '\n')
        mx_print_invalid_line(*line, path);
    (*line)++;
    return i;
}

void mx_error_invalid_line(t_islands *path) {
    int line = 1;

    for (int i = 0; path->file_in_str[i] != '\0'; i++) {
        if (line == 1) {
            if (i > 0 && path->file_in_str[i] == '\n') {
                line++;
                continue;
            }
            if (!mx_isdigit(path->file_in_str[i]) || !path->file_in_str[i + 1])
                mx_print_invalid_line(line, path);
        }
        if (line > 1) {
            i = second_line_check(path, path->file_in_str, &line, i);
        }
    }
}

