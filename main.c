#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(char *str);

int main(int ac, char **av) {
  printf("size_t i = %ld\n", ft_strlen(av[1]));
  return (0);
}
