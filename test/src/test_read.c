#include "tester.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void test_read(void) {

  printf("######TESTING READ######\n\n");
  const char *write_only = "./test/test_read.txt";
  const char *read_only = "./Makefile";
  const char *valid = "./compile_flags.txt";
  int fd_valid = open(valid, O_RDWR);
  if (fd_valid == FAILURE) {
    printf(RED "Fail to open %s\n" RESET, valid);
  }
  int fd_write_only = open(write_only, O_WRONLY);
  if (fd_write_only == FAILURE) {
    printf(RED "Fail to open %s\n" RESET, write_only);
    perror(NULL);
  }
  int fd_read_only = open(read_only, O_RDONLY);
  if (fd_read_only == FAILURE) {
    printf(RED "Fail to open %s\n" RESET, read_only);
  };
  int fd_invalid = -1;

  errno = 0;
  char buf[1000] = {0};

  ssize_t ret = read(fd_valid, buf, 1000);
  buf[ret] = '\0';
  int errno_save = errno;
  printf("Read from valid file (%s) with fd (%d):\nReturn read: %ld; buf: %s; "
         "errno = %d; perror: \n",
         valid, fd_valid, ret, buf, errno_save);
  print_result(errno_save == 0 && fd_valid > 0);
  printf("-----------------\n");
  errno = 0;

  buf[0] = '\0';
  ret = read(fd_read_only, buf, 1000);
  buf[ret] = '\0';
  errno_save = errno;
  printf(
      "Read from read only file (%s) with fd (%d):\nReturn read: %ld; buf: %s; "
      "errno = %d; perror: \n",
      read_only, fd_read_only, ret, buf, errno_save);
  print_result(errno_save == 0 && fd_read_only > 0);
  printf("-----------------\n");
  errno = 0;

  buf[0] = '\0';
  ret = read(fd_write_only, buf, 1000);
  buf[ret] = '\0';
  errno_save = errno;
  printf("Read from write only file (%s) with fd (%d):\nReturn read: %ld; buf: "
         "%s; "
         "errno = %d; perror: \n",
         write_only, fd_write_only, ret, buf, errno_save);
  perror(NULL);
  print_result(errno_save != 0 && fd_write_only > 0);
  printf("-----------------\n");
  errno = 0;

  buf[0] = '\0';
  ret = read(fd_invalid, buf, 1000);
  buf[ret] = '\0';
  errno_save = errno;
  printf(
      "Read from non existent file with fd (%d):\nReturn read: %ld; buf: %s; "
      "errno = %d; perror: \n",
      fd_invalid, ret, buf, errno_save);
  perror(NULL);
  print_result(errno_save != 0);
  printf("-----------------\n");
  errno = 0;
}
