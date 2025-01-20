#include "tester.h"

void print_success(void) { printf("  ==> " GREEN "Success\n" RESET); }

void print_failure(void) { printf("  ==> " RED "Failure\n" RESET); }

void print_result(bool result) {
  void (*result_function[2])(void);
  result_function[1] = print_success;
  result_function[0] = print_failure;
  result_function[result]();
}
