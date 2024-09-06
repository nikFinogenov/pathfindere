#include <libmx.h>

void *mx_realloc(void *ptr, size_t size) {
    if (!size && ptr) {
        free(ptr);
        return NULL;
    }

    if (!ptr && size)
        return malloc(size);

    size_t ptr_size = size; 
    
    void *new = malloc(size);

    if (!new)
        return NULL;
    
    new = mx_memmove(new, ptr, ptr_size);

    free(ptr);
    return new;
}
