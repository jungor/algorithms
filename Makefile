#IDIR =.
#CC=gcc
#CFLAGS=-I$(IDIR)

#ODIR=obj
#LDIR =../lib

#LIBS=-lm

_DEPS = utils.h
#DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
DEPS = $(_DEPS)

BIN = main

_OBJ = $(BIN).c utils.c $(subst ./, ,$(wildcard ./chap*/*.c))
#OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_OBJ))
OBJ = $(patsubst %.c, %.o, $(_OBJ))

$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

#$(BIN).o: main.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.c %.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean run

run:
	./$(BIN)

clean:
	#rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
	rm -f $(OBJ) $(BIN)
