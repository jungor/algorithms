BIN = main

SRCS = $(BIN).c utils.c $(subst ./, ,$(wildcard ./chap*/*.c))
OBJS = $(patsubst %.c, %.o, $(SRCS))

CC      = gcc 
CFLAGS  = -Wall -g
INCLUDEFLAGS = 
LDFLAGS = 
TARGET = main

.PHONY:run
run: all
	./$(TARGET)

.PHONY:all 
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDEFLAGS)

%.d:%.c
	@set -e; rm -f $@; $(CC) -MM $< $(INCLUDEFLAGS) > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(OBJS:.o=.d)

.PHONY:clean
clean:
	rm -f $(TARGET) $(OBJS) **/*.d **/*.d.*

.PHONY:debug
debug:
	gdb $(TARGET)

.PHONY:dump
dump:
	less $(TARGET).exe.stackdump
