CFLAGS = $(EXTRA_FLAGS) -O3 -Wall -Wextra -std=gnu99 -pedantic
LIBS =


all: cpu ram

cpu:
	$(CC) $(CFLAGS) -o cpu cpu.c $(LIBS)

ram:
	$(CC) $(CFLAGS) -o ram ram.c $(LIBS)

clean:
	-rm cpu ram
