	.tramp		:
	{
	  tramp_start = .;
	  regs___ = tramp_start + 16;
	  CREATE_OBJECT_SYMBOLS
	  trampoline.o
	  tramp_end = .;
	}
