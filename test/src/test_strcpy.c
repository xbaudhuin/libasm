#include "tester.h"
#include <string.h>

void test_strcpy(void) {
  char dest_str_ft_strcpy[10] = {0};
  char dest_str_strcpy[10] = {0};
  char dest_empty_ft_strcpy[10] = {0};
  char dest_empty_strcpy[10] = {0};
  char dest_str_with_0_ft_strcpy[10] = {0};
  char dest_str_with_0_strcpy[10] = {0};
  char *str = "bonjour";
  const char *empty = "";
  char str_with_0[11];

  str_with_0[0] = 'H', str_with_0[1] = 'e', str_with_0[2] = 'l',
  str_with_0[3] = 'l', str_with_0[4] = 'o', str_with_0[5] = '\0',
  str_with_0[6] = 'W', str_with_0[7] = 'o', str_with_0[8] = 'r',
  str_with_0[9] = 'l', str_with_0[10] = 'd';

  char *ft_strcpy_str = ft_strcpy(dest_str_ft_strcpy, str);
  char *strcpy_str = strcpy(dest_str_strcpy, str);

  char *ft_strcpy_empty = ft_strcpy(dest_empty_ft_strcpy, empty);
  char *strcpy_empty = strcpy(dest_empty_strcpy, empty);

  char *ft_strcpy_str_with_0 = ft_strcpy(dest_str_with_0_ft_strcpy, str_with_0);
  char *strcpy_str_with_0 = strcpy(dest_str_with_0_strcpy, str_with_0);

  printf("######TESTING strcpy######\n\n"
         "ft_strcpy(dest_ft_strcpy, \"%s\"): %s ; strcpy(dest_strcpy, \"%s\") "
         "= %s",
         str, ft_strcpy_str, str, strcpy_str);
  print_result(strcmp(ft_strcpy_str, strcpy_str) == 0);

  printf(
      "ft_strcpy(dest_ft_strcpy, \"\") = %s ; strcpy(dest_strcpy, \"\") = %s",
      ft_strcpy_empty, strcpy_empty);
  print_result(strcmp(ft_strcpy_empty, strcpy_empty) == 0);

  printf("ft_strcpy(dest_ft_strcpy, \"Hello\\0World) = %s ; "
         "strcpy(dest_strcpy, \"Hello\\0World\") = %s",
         ft_strcpy_str_with_0, strcpy_str_with_0);
  print_result(strcmp(ft_strcpy_str_with_0, strcpy_str_with_0) == 0);
  printf("\n\n");
}
