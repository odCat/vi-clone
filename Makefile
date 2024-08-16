override CFLAGS += -lncurses -Wall -Wextra -Wno-unused-variable -pedantic

vi: main.c
	$(CC) -o vi main.c $(CFLAGS)

.PHONY: clean
clean:
	-rm a.exe a.out vi *.o
