CFLAGS = $(EXTRA_FLAGS) -O3 -Wall -Wextra -std=gnu99 -pedantic
LIBS =


all: cpu ram disk nvidia

cpu:
	$(CC) $(CFLAGS) -o cpu cpu.c $(LIBS)

ram:
	$(CC) $(CFLAGS) -o ram ram.c $(LIBS)

disk:
	$(CC) $(CFLAGS) -o disk disk.c $(LIBS)

nvidia:
	$(CC) $(CFLAGS) -o nvidia nvidia.c $(LIBS)

clean:
	-rm cpu ram disk nvidia
