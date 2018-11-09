	.tramp		:
	{
	  tramp_start = .;
	  regs_start = tramp_start + 16;
	  saved_regs = regs_start;
	  /**
	  * create a hole for storing registers, 32 general-purpose regs,
	  * and 6 control regs
          * (8 * (64 * (32 + 6)))
	  * linker size is in number of bits	  
	  **/
	  . += (64 * (32 + 6));
	  regs_end = .;
	  trampoline.o
	  tramp_end = .;
	}
