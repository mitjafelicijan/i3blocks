#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void progress_bar(int used, int width) {
  int progress = (used * width) / 100;
  int remaining = width - progress;

  for (int i = 0; i < progress; i++) {
	printf("▓");
  }
  for (int i = 0; i < remaining; i++) {
	printf("░");
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  FILE *fp;
  char path[256];
  char *endptr;
  double used;

  int opt;
  int width = 10;

  while ((opt = getopt(argc, argv, "w:")) != -1) {
	switch (opt) {
	case 'w':
	  width = atoi(optarg);
	  break;
	default:
	  fprintf(stderr, "Usage: %s -w <value>\n", argv[0]);
	  exit(EXIT_FAILURE);
	}
  }

  fp = popen("mpstat 1 1 | grep Average | awk '{ print $NF }'", "r");
  if (fp == NULL) {
	fprintf(stderr,"cpu: failed to execute command\n");
	exit(EXIT_FAILURE);
  }

  if (fgets(path, sizeof(path), fp) != NULL) {
	used = strtod(path, &endptr);
	if (*endptr != '\n') {
	  fprintf(stderr, "cpu: failed to convert the response to a number\n");
	  exit(EXIT_FAILURE);
	}

	progress_bar((int)(100-used), width);
  } else {
	fprintf(stderr, "cpu: no output from command\n");
	exit(EXIT_FAILURE);
  }

  pclose(fp);
  exit(EXIT_SUCCESS);
}
