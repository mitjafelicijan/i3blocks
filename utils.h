#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void display_progress_bar(int used, int width, int show_percentage) {
  int progress = (used * width) / 100;
  int remaining = width - progress;

  for (int i = 0; i < progress; i++) printf("▓");
  for (int i = 0; i < remaining; i++) printf("░");
  if (show_percentage) printf(" %3d%%", used);
  printf("\n");
}

int get_arg_value(char* flag, int argc, char* argv[], int default_value) {
  for (int i = 1; i < argc; i++) {
	if (strcmp(argv[i], flag) == 0) {
	  if (i + 1 < argc) {
		return atoi(argv[i + 1]);
	  } else {
		fprintf(stderr, "no value provided for flag %s\n", flag);
		exit(EXIT_FAILURE);
	  }
	}
  }
  return default_value;
}

int get_cmd_value(char* cmd) {
  FILE *fp;
  char path[256];
  char *endptr;
  double val;

  fp = popen(cmd, "r");
  if (fp == NULL) {
	fprintf(stderr,"failed to execute command\n");
	exit(EXIT_FAILURE);
  }

  if (fgets(path, sizeof(path), fp) != NULL) {
	val = strtod(path, &endptr);
	if (*endptr != '\n') {
	  fprintf(stderr, "failed to convert the response to a number\n");
	  exit(EXIT_FAILURE);
	}
  } else {
	fprintf(stderr, "no output from command\n");
	exit(EXIT_FAILURE);
  }

  pclose(fp);
  return (int)val;
}
