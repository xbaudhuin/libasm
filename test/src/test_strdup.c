#include "tester.h"

void test_strdup(void) {
  char *test1_ft_strdup = ft_strdup("");
  const int errno_test1_ft_strdup = errno;
  char *test1_strdup = strdup("");
  const int errno_test1_strdup = errno;

  char *test2_ft_strdup = ft_strdup("bonjour");
  const int errno_test2_ft_strdup = errno;
  char *test2_strdup = strdup("bonjour");
  const int errno_test2_strdup = errno;

  char *test3_ft_strdup = ft_strdup("bon\0jour");
  const int errno_test3_ft_strdup = errno;
  char *test3_strdup = strdup("bon\0jour");
  const int errno_test3_strdup = errno;

  printf("######TESTING strdup######\n\n");

  printf("test 1 : \"\"; ft_strdup: %s, errno = %d ; strdup: %s, errno = %d",
         test1_ft_strdup, errno_test1_ft_strdup, test1_strdup,
         errno_test1_strdup);
  print_result(strcmp(test1_strdup, test1_ft_strdup) == 0 &&
               errno_test1_ft_strdup == errno_test1_strdup);
  free(test1_ft_strdup);
  free(test1_strdup);

  printf("test 2 : \"bonjour\"; ft_strdup: %s, errno = %d ; strdup: %s, errno "
         "= %d",
         test2_ft_strdup, errno_test2_ft_strdup, test2_strdup,
         errno_test2_strdup);
  print_result(strcmp(test2_strdup, test2_ft_strdup) == 0 &&
               errno_test2_ft_strdup == errno_test2_strdup);
  free(test2_ft_strdup);
  free(test2_strdup);

  printf("test 3 : \"bon\\0jour\"; ft_strdup: %s, errno = %d ; strdup: %s, "
         "errno = %d",
         test3_ft_strdup, errno_test3_ft_strdup, test3_strdup,
         errno_test3_strdup);
  print_result(strcmp(test3_strdup, test3_ft_strdup) == 0 &&
               errno_test3_ft_strdup == errno_test3_strdup);
  free(test3_ft_strdup);
  free(test3_strdup);

  char *dump = malloc(50000);
  if (dump) {
    memset(dump, 0, 50000);
  }
  dump[550] = 'a';
  if (dump == NULL) {
    printf(RED "FAIL to allocate dump\n" RESET);
  } else {
    printf(GREEN "dump is allocated\n" RESET);
  }
  char *dump2 = malloc(50000);
  if (dump2) {
    memset(dump2, 0, 50000);
  }
  dump2[550] = 'b';
  printf("%s\n", dump);
  if (dump2 == NULL) {
    printf(RED "FAIL to allocate dump\n" RESET);
  } else {
    printf(GREEN "dump is allocated\n" RESET);
  }
  char *test4_ft_strdup = ft_strdup("FAIL MALLOC                               "
                                    "                                        ");
  const int errno_test4_ft_strdup = errno;
  char *test4_strdup = ft_strdup("FAIL MALLOC                               "
                                 "                                        ");
  const int errno_test4_strdup = errno;
  free(dump);

  printf("test 4 : \"FAIL MALLOC (long chain)\"; ft_strdup: %s, errno = %d ; "
         "strdup: %s, "
         "errno = %d",
         test4_ft_strdup, errno_test4_ft_strdup, test4_strdup,
         errno_test4_strdup);
  print_result(strcmp(test4_strdup, test4_ft_strdup) == 0 &&
               errno_test4_strdup == errno_test4_ft_strdup);
  free(test4_ft_strdup);
  free(test4_strdup);
}
