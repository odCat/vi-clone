override CFLAGS += -lncurses -Wall

vi: main.c
	cc -o vi main.c $(CFLAGS)

.PHONY: clean
clean:
	@rm vi *.o
