#include <stdio.h>
#include <unistd.h>

#include <errno.h>

int main() {
  errno = 1;
  write(1, "Hello", 5);
  return (0);
}
