#include "tester.h"

void test_strlen() {
  const char *str = "bonjour";
  const char *empty = "";
  char str_with_0[11];

  str_with_0[0] = 'H', str_with_0[1] = 'e', str_with_0[2] = 'l',
  str_with_0[3] = 'l', str_with_0[4] = 'o', str_with_0[5] = '\0',
  str_with_0[6] = 'W', str_with_0[7] = 'o', str_with_0[8] = 'r',
  str_with_0[9] = 'l', str_with_0[10] = 'd';

  const size_t ft_strlen_str = ft_strlen(str);
  const size_t strlen_str = strlen(str);

  const size_t ft_strlen_empty = ft_strlen(empty);
  const size_t strlen_empty = strlen(empty);

  const size_t ft_strlen_str_with_0 = ft_strlen(str_with_0);
  const size_t strlen_str_with_0 = strlen(str_with_0);

  printf("######TESTING STRLEN######\n\n"
         "ft_strlen(\"%s\"): %ld ; strlen(\"%s\") = %ld",
         str, ft_strlen_str, str, strlen_str);
  print_result(ft_strlen_str == strlen_str);

  printf("ft_strlen(\"\") = %ld ; strlen(\"\") = %ld", ft_strlen_empty,
         strlen_empty);
  print_result(ft_strlen_empty == strlen_empty);

  printf("ft_strlen(\"Hello\\0World) = %ld ; strlen(\"Hello\\0World\") = %ld",
         ft_strlen_str_with_0, strlen_str_with_0);
  print_result(ft_strlen_str_with_0 == strlen_str_with_0);
  printf("\n\n");
}
