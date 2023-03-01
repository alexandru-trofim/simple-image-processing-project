IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR= src

_DEPS = bmp_header.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = draw_commands.o edit_save_commands.o insert_command.o main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	rm build
	rm *.bmp
