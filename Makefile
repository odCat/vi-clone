override CFLAGS += -lncurses -Wall -Wextra -Wno-unused-variable -pedantic
SRC = *.c
HDR = *.h
OBJ = *.o

vi: $(OBJ)
	$(CC) -o vi $(OBJ) $(CFLAGS)

$(OBJ): $(SRC) $(HDR)
	$(CC) -c $(SRC)

.PHONY: clean
clean:
	-rm a.exe a.out vi *.o
