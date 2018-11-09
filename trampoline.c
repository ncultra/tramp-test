#include "tramp_test.h"

extern unsigned long regs_start, regs_end, tramp_start, tramp_end;
extern uint64_t saved_regs[];


void __attribute__((section(".tramp"))) top(void)
{
top_again:

   printf("address of regs_start:      0x%08lx\n", (uint64_t)&regs_start);
   printf("address of regs_end:        0x%08lx\n", (uint64_t)&regs_end);
   uint64_t size = ((&regs_end - &regs_start) * CHAR_BIT);
   printf("size of saved_regs:         0x%08lx\n", size);
   printf("address of tramp_start:     0x%08lx\n", (uint64_t)&tramp_start);
   printf("address of tramp_end:       0x%08lx\n", (uint64_t)&tramp_end);
   printf("size of section .tramp:     0x%08lx\n", (&tramp_end - &tramp_start) * CHAR_BIT);
   void *position = &&top_again;
   printf("address of label top_again: 0x%08lx\n", (uint64_t)position);
   printf("bits in unsigned char:      0x%08lx\n", (uint64_t)CHAR_BIT);
   return;
}

void __attribute__((section(".tramp"))) land_here(void)
{
   struct reg_state *rstate = NULL;
   uint64_t offset_of = (uint64_t)&land_here - (uint64_t)saved_regs;
   printf("landed here                 0x%08lx\n", (uint64_t)&land_here);
   printf("land_here - saved_regs =    0x%08lx\n", offset_of);
   rstate = (void *)&land_here - offset_of;
   printf("address of rstate:          0x%08lx\n", (uint64_t)rstate);
   printf("rstate[0].gp_regs[13]       0x%08lx\n", rstate[0].gp_regs[13]);
   rstate[6].gp_regs[3] = 3UL;
   printf("rstate[6].gp_regs[3]        0x%08lx\n", rstate[6].gp_regs[3]);
   top();  
}
