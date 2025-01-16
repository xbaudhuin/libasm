#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(char *str);
extern char *ft_strcpy(char *dest, const char *src);

int main(int ac, char **av) {
  char dest[10] = {0};
  char *test = ft_strcpy(dest, av[1]);
  printf("dest = %s\ntest = %s\n", dest, test);
  return (0);
}
