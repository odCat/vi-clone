override CFLAGS += `pkg-config --cflags glib-2.0` -Wall -Wextra -Wno-unused-variable -pedantic
LDLIBS = `pkg-config --libs ncurses glib-2.0`
SRC = *.c
TDIR = tests
TST = $(TDIR)/*.c
HDR = *.h
OBJ = *.o

.PHONY: clean
.PHONY: test

vi: $(OBJ)
	$(CC) $(CFLAGS) -o vi $(OBJ) $(LDLIBS)

$(OBJ): $(SRC) $(HDR)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	-rm a.exe a.out vi *.o *.tap
	-rm $(TDIR)/*.o $(TDIR)/*.tap $(TDIR)/test

test: $(TDIR)/*.tap
	prove -v $(TDIR)/*.tap

$(TDIR)/*.tap: $(TST)
	$(CC) $(CFLAGS) -c $(TST) -o $(TDIR)/test.o
	$(CC) $(CFLAGS) -o $(TDIR)/test $(TDIR)/test.o $(LDLIBS)
	$(TDIR)/test --tap > $(TDIR)/test.tap
