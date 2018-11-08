EXE=tramp_test
LINK_SCRIPT=$(EXE).ld
CC	:= gcc
CFLAGS =  -Wall -Werror -fPIC -std=gnu11
LFLAGS = -Xlinker --script $(LINK_SCRIPT)

OBJS=tramp_test.o trampoline.o
CLEAN=rm -f $(EXE) *.o *.a *.tramp *.so *.S *.map

.PHONY: all
all: clean tramp_test

trampoline.o: trampoline.c
	$(CC) -c -nostdlib $(CFLAGS) -o trampoline.o trampoline.c

.PHONY: tramp_test
tramp_test: $(OBJS)
	$(CC) $(LFLAGS)  $(CFLAGS) -o $(EXE) $(OBJS)
	objdump -D -S $(EXE) > $(EXE).S

.PHONY: clean
clean:
	$(shell $(CLEAN) &> /dev/null)
	@echo "repo is clean"

.PHONY: superclean
superclean: clean
	$(shell rm *~ &> /dev/null)
	@echo "cleaned unwanted backup files"

.PHONY: test
test:
	@echo $(shell ./$(EXE) --desc --flags c09b --base 49ffffc3 --limit fffff)
	@echo $(shell ./$(EXE) --selector --index 7 --table 0 --rpl 3)
	@echo $(shell ./$(EXE) --gdt-entry 0x08888888888888888)
	@echo $(shell ./$(EXE) --sel-entry 0x88888888)
	@echo $(shell ./$(EXE) --host-sel)
	@echo $(shell ./$(EXE) --host-gdt)
	@echo $(shell ./$(EXE) --linux-sel)
	@echo $(shell ./$(EXE) --linux-gdt)
