#ifndef TESTER_H
#define TESTER_H

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../../include/libasm.h"

#define RED "\033[1;31m"
#define RESET "\033[0m"
#define PURP "\033[1;95m"
#define PURP2 "\033[1;35m"
#define ORANGE "\033[1;91m"
#define LIGHTB "\033[1;36m"
#define BLUE "\033[1;94m"
#define GREEN "\033[1;92m"
#define YELLOW "\033[1;93m"

void test_strlen(void);
void test_strcpy(void);
void test_strcmp(void);
void test_strdup(void);
void print_result(bool result);

#endif // !TESTER_H
