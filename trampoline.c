#include "tramp_test.h"

extern unsigned long regs_start, regs_end, tramp_start, tramp_end;
extern unsigned long saved_regs[];


void __attribute__((section(".tramp"))) top(void)
{
top_again:

   printf("address of regs_start:      0x%08lx\n", (unsigned long)&regs_start);
   printf("address of regs_end:        0x%08lx\n", (unsigned long)&regs_end);
   unsigned long size = (&regs_end - &regs_start) * CHAR_BIT;
   printf("size of saved_regs:         0x%08lx\n", size);
   printf("address of tramp_start:     0x%08lx\n", (unsigned long)&tramp_start);
   printf("address of tramp_end:       0x%08lx\n", (unsigned long)&tramp_end);
   printf("size of section .tramp:     0x%08lx\n", (&tramp_end - &tramp_start) * CHAR_BIT);
   void *position = &&top_again;
   printf("address of label top_again: 0x%08lx\n", (unsigned long)position);
   printf("bits in unsigned char:      0x%08lx\n", (unsigned long)CHAR_BIT);
   return;
}

void __attribute__((section(".tramp"))) land_here(void)
{
   top();
   printf("landed here\n");
   
}
