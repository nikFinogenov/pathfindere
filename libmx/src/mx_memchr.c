#include <libmx.h>

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *p = (const unsigned char *)s;

    for (size_t i = 0; i < n; i++) {
        if (p[i] == (unsigned char)c) {
            return (void *)(p + i);
        }
    }

    return NULL;
}
