#include "tester.h"

void test_strcpy(void) {
  char *dest_ const char *str = "bonjour";
  const char *empty = "";
  char str_with_0[11];

  str_with_0[0] = 'H', str_with_0[1] = 'e', str_with_0[2] = 'l',
  str_with_0[3] = 'l', str_with_0[4] = 'o', str_with_0[5] = '\0',
  str_with_0[6] = 'W', str_with_0[7] = 'o', str_with_0[8] = 'r',
  str_with_0[9] = 'l', str_with_0[10] = 'd';

  const size_t ft_strcpy_str = ft_strcpy(str);
  const size_t strcpy_str = strcpy(str);

  const size_t ft_strcpy_empty = ft_strcpy(empty);
  const size_t strcpy_empty = strcpy(empty);

  const size_t ft_strcpy_str_with_0 = ft_strcpy(str_with_0);
  const size_t strcpy_str_with_0 = strcpy(str_with_0);

  printf("######TESTING strcpy######\n\n"
         "ft_strcpy(\"%s\"): %ld ; strcpy(\"%s\") = %ld",
         str, ft_strcpy_str, str, strcpy_str);
  print_result(ft_strcpy_str == strcpy_str);

  printf("ft_strcpy(\"\") = %ld ; strcpy(\"\") = %ld", ft_strcpy_empty,
         strcpy_empty);
  print_result(ft_strcpy_str == strcpy_str);

  printf("ft_strcpy(\"Hello\\0World) = %ld ; strcpy(\"Hello\\0World\") = %ld",
         ft_strcpy_str_with_0, strcpy_str_with_0);
  print_result(ft_strcpy_str == strcpy_str);
  printf("\n\n");
}
