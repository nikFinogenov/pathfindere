#include <libmx.h>

char *mx_strtok(char *str, const char *delimiters) {
    static char *lastToken = NULL;
    if (str != NULL) {
        lastToken = str;
    } else if (lastToken == NULL) {
        return NULL;
    }

    while (*lastToken != '\0' && mx_strchr(delimiters, *lastToken) != NULL) {
        lastToken++;
    }

    if (*lastToken == '\0') {
        lastToken = NULL;
        return NULL;
    }

    char *tokenStart = lastToken;
    while (*lastToken != '\0' && mx_strchr(delimiters, *lastToken) == NULL) {
        lastToken++;
    }

    if (*lastToken != '\0') {
        *lastToken = '\0';
        lastToken++;
    }

    return tokenStart;
}
