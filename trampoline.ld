	.tramp		:
	{
	  tramp_start = .;
	  . += 16;
	  regs_start = .;
	  saved_regs = regs_start;
	  /**
	  * create a hole for storing registers, 32 general-purpose regs,
	  * and 6 control regs
          * (8 * (64 * (32 + 6)))
	  * linker size is in number of bits, so this is an array of
	  * uint64_t regs[8][38];	  	  
	  **/
	  . += (8 * (64 * (32 + 6)));
	  regs_end = .;
	  trampoline.o
	  tramp_end = .;
	}
