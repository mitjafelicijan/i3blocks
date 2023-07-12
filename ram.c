#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define UTILS_IMPLEMENTATION
#include "utils.h"

int main(int argc, char *argv[]) {
  int percentage = get_arg_value("-p", argc, argv, 0);
  int width = get_arg_value("-w", argc, argv, 10);

  int available_mb = get_cmd_value("free --mega | grep 'Mem' | awk '{print $2}'");
  int used_mb = get_cmd_value("free --mega | grep 'Mem' | awk '{print $3}'");
  int used = (used_mb * 100) / (available_mb + used_mb);

  display_progress_bar(used, width, percentage);
  exit(EXIT_SUCCESS);
}
