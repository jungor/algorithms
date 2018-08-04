CC=gcc
CFLAGS=-Wall -g -std=gnu99
INCLUDEFLAGS=
# 注意链接参数必须放在目标后面
LDLIBS=-lcunit -lm

DLTDEP=rm -f *.d chap*/*.d

TARGET = main
TESTTG = test_main

TARGETSRC = $(addsuffix .c, $(TARGET))
TESTTGSRC = $(addsuffix .c, $(TESTTG))

IGNSRCS = play.c
ALLFILES= $(subst ./, , $(wildcard ./*.[ch]) $(wildcard ./chap*/*.[ch]))
ALLSRCS = $(filter-out $(IGNSRCS), $(subst ./, , $(wildcard ./*.c) $(wildcard ./chap*/*.c)))
TSTSRCS = $(subst ./, , $(wildcard ./test*.c) $(wildcard ./chap*/test*.c))

TARGETDEPSRCS = $(filter-out $(TSTSRCS), $(ALLSRCS))
TESTTGDEPSRCS = $(filter-out $(TARGETSRC), $(ALLSRCS))
TARGETDEPOBJS = $(patsubst %.c, %.o, $(TARGETDEPSRCS))
TESTTGDEPOBJS = $(patsubst %.c, %.o, $(TESTTGDEPSRCS))

.PHONY:all 
all: $(TARGET) $(TESTTG) tags

$(TARGET): $(TARGETDEPOBJS)
	$(CC) -o $@ $^ $(LDLIBS)
	$(DLTDEP)

$(TESTTG): $(TESTTGDEPOBJS)
	$(CC) -o $@ $^ $(LDLIBS)
	$(DLTDEP)

# 要么把所有源文件加到依赖；要么设为phony。
# 否则首次生成过tags之后后续会因为已存在不再生成
tags: $(ALLFILES)
	ctags -R .

# %.o: %.c
	# $(COMPILE) $< -o $@

# 使用gcc的-MM选项自动生成各源文件的依赖
%.d: %c
	$(CC) -MM $< $(INCLUDEFLAGS) | awk '{if ($$1 ~ /o:$$/) $$1 = "$*.o:"; print $$0}' > $@;

#  导入依赖
-include $(ALLSRCS:.c=.d)

.PHONY:clean
clean:
	rm -f $(TARGET) $(TESTTG) $(TARGETDEPOBJS) $(TESTTGDEPOBJS)

.PHONY:run
run: all
	@./$(TESTTG)

.PHONY:var
var:
	@echo TSTSRCS: $(TSTSRCS)
