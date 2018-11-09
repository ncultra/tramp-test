EXE=tramp_test
LINK_SCRIPT=$(EXE).ld
CC	:= gcc
CFLAGS = -c -g  -Wall -Werror -fPIC -std=gnu11
CEXTRA = -nostdlib
LFLAGS = -Xlinker --script $(LINK_SCRIPT)

OBJS = trampoline.o  tramp_test.o 
CLEAN = rm -f $(EXE) *.o *.a *.tramp *.so *.S *.map *.asm

.PHONY: all
all: tramp_test mapfile

#*.o: *.c
#	$(CC) $(CFLAGS) $<

.PHONY: tramp_test
tramp_test: $(OBJS)
	$(CC) $(LFLAGS) -o $(EXE) $(OBJS)
	$(shell ./dis.sh *.o)


.PHONY: mapfile
mapfile: $(EXE)
	$(shell ld -M=tramp_test.map -o /dev/null $(EXE) &> /dev/null)

.PHONY: clean
clean:
	$(shell $(CLEAN) &> /dev/null)
	@echo "repo is clean"

.PHONY: superclean
superclean: clean
	$(shell rm *~ &> /dev/null)
	@echo "cleaned unwanted backup files"

.PHONY: test
test: FORCE
	./tramp_test

FORCE:
