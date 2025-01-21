#include "tester.h"

void test_strcmp(void) {

  const int test1_ft_strcmp = ft_strcmp("", "");
  const int test1_strcmp = strcmp("", "");

  const int test2_ft_strcmp = ft_strcmp("bonjour", "");
  const int test2_strcmp = strcmp("bonjour", "");

  const int test3_ft_strcmp = ft_strcmp("", "bonjour");
  const int test3_strcmp = strcmp("", "bonjour");

  const int test4_ft_strcmp = ft_strcmp("bonjour", "bonjour");
  const int test4_strcmp = ft_strcmp("bonjour", "bonjour");

  const int test5_ft_strcmp = ft_strcmp("bon\0jour", "bonjour");
  const int test5_strcmp = ft_strcmp("bon\0jour", "bonjour");

  const int test6_ft_strcmp = ft_strcmp("bon\0jour", "bonj\0our");
  const int test6_strcmp = ft_strcmp("bon\0jour", "bonj\0our");

  const int test7_ft_strcmp = ft_strcmp("aaa", "aaz");
  const int test7_strcmp = ft_strcmp("aaa", "aaz");

  const int test8_ft_strcmp = ft_strcmp("aaz", "aaa");
  const int test8_strcmp = ft_strcmp("aaz", "aaa");

  const int test9_ft_strcmp = ft_strcmp("bonjour", "bon");
  const int test9_strcmp = ft_strcmp("bonjour", "bon");

  printf("######TESTING strcmp######\n\n");

  printf("test 1: strcmp(\"\", \"\"): ft_strcmp: %d; strcmp: %d; ",
         test1_ft_strcmp, test1_strcmp);
  print_result((test1_strcmp == 0) == (test1_ft_strcmp == 0));

  printf("test 2: strcmp(\"bonjour\", \"\"): ft_strcmp: %d; strcmp: %d; ",
         test2_ft_strcmp, test2_strcmp);
  print_result((test2_strcmp >= 0) == (test2_ft_strcmp >= 0));

  printf("test 3: strcmp(\"\", \"bonjour\"): ft_strcmp: %d; strcmp: %d; ",
         test3_ft_strcmp, test3_strcmp);
  print_result((test3_strcmp > 0) == (test3_ft_strcmp > 0));

  printf(
      "test 4: strcmp(\"bonjour\", \"bonjour\"): ft_strcmp: %d; strcmp: %d; ",
      test4_ft_strcmp, test4_strcmp);
  print_result((test4_strcmp == 0) == (test4_ft_strcmp == 0));

  printf("test 5: strcmp(\"bon\\0jour\", \"bonjour\"): ft_strcmp: %d; strcmp: "
         "%d; ",
         test5_ft_strcmp, test5_strcmp);
  print_result((test5_strcmp > 0) == (test5_ft_strcmp > 0));

  printf("test 6: strcmp(\"bon\\0jour\", \"bon\\0jour\"): ft_strcmp: %d; "
         "strcmp: %d; ",
         test6_ft_strcmp, test6_strcmp);
  print_result((test6_strcmp > 0) == (test6_ft_strcmp > 0));

  printf("test 7: strcmp(\"aaz\", \"aaa\"): ft_strcmp: %d; "
         "strcmp: %d; ",
         test7_ft_strcmp, test7_strcmp);
  print_result((test7_strcmp > 0) == (test7_ft_strcmp > 0));

  printf("test 8: strcmp(\"aaa\", \"aaz\"): ft_strcmp: %d; "
         "strcmp: %d; ",
         test8_ft_strcmp, test8_strcmp);
  print_result((test8_strcmp > 0) == (test8_ft_strcmp > 0));

  printf("test 9: strcmp(\"bonjour\", \"bon\"): ft_strcmp: %d; "
         "strcmp: %d; ",
         test9_ft_strcmp, test9_strcmp);
  print_result((test9_strcmp > 0) == (test9_ft_strcmp > 0));
  printf("\n\n");
}
