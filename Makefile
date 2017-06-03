ALLSRCS = utils.c $(subst ./,,$(wildcard ./chap*/*.c))
TESTSRCS = $(subst ./,,$(wildcard ./chap*/test*.c))
SRCS = $(filter-out $(TESTSRCS), $(ALLSRCS))
ALLOBJS = $(patsubst %.c, %.o, $(ALLSRCS))
OBJS = $(patsubst %.c, %.o, $(SRCS))

CC      = gcc 
CFLAGS  = -Wall -g
INCLUDEFLAGS = 
LDFLAGS = -lcunit
TARGET = main
TEST = test

.PHONY:run
run: all
	./$(TEST)

.PHONY:all 
all: $(TARGET) $(TEST)

$(TARGET): $(addsuffix .o, $(TARGET)) $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(TEST): $(addsuffix .o, $(TEST)) $(ALLOBJS)
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
.PHONY:var
var:
	@echo ALLSRCS: $(ALLSRCS)
	@echo TESTSRCS: $(TESTSRCS)
	@echo SRCS: $(SRCS)
	@echo ALLOBJS: $(ALLOBJS)
	@echo OBJS: $(OBJS)
