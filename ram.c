#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils.h"

int main(int argc, char *argv[]) {
  int percentage = get_arg_value("-p", argc, argv, 0);
  int width = get_arg_value("-w", argc, argv, 10);

  exit(EXIT_SUCCESS);
}
