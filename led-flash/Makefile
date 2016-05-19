CC=$(CROSS_COMPILE)gcc
CFLAGS=-Wall -g
PROGS=led-flash

all: $(PROGS)

led-flash: led-flash.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f $(PROGS)

install:
	cp $(PROGS) $(TARGET_DIR)/bin
