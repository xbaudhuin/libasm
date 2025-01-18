#ifndef LIBASM_H
#define LIBASM_H

#include <stdlib.h>

char *ft_strdup(const char *s);
char *ft_strcpy(char *dst, const char *src);

size_t ft_strlen(const char *str);

ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);

#endif // LIBASM_H
