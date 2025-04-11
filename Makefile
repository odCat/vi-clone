override CFLAGS += `pkg-config --cflags glib-2.0` -Wall -Wextra -Wno-unused-variable -pedantic
LDLIBS = `pkg-config --libs ncurses glib-2.0`
SRC = *.c
HDR = *.h
OBJ = *.o

vi: $(OBJ)
	$(CC) $(CFLAGS) -o vi $(OBJ) $(LDLIBS)

$(OBJ): $(SRC) $(HDR)
	$(CC) $(CFLAGS) -c $(SRC)

.PHONY: clean
clean:
	-rm a.exe a.out vi *.o
