#define UTILS_IMPLEMENTATION
#include "utils.h"

int main(int argc, char *argv[]) {
  int percentage = get_arg_value("-p", argc, argv, 0);
  int width = get_arg_value("-w", argc, argv, 10);

  int used = get_cmd_value("df -h / | awk 'NR==2{print $5}' | sed -e 's/%//'");
  display_progress_bar(used, width, percentage);

  exit(EXIT_SUCCESS);
}
