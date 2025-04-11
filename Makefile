override CFLAGS += -Wall -Wextra -Wno-unused-variable -pedantic
LDLIBS = -lncurses
SRC = *.c
HDR = *.h
OBJ = *.o

vi: $(OBJ)
	$(CC) $(CFLAGS) -o vi $(OBJ) $(LDLIBS)

$(OBJ): $(SRC) $(HDR)
	$(CC) -c $(SRC)

.PHONY: clean
clean:
	-rm a.exe a.out vi *.o
