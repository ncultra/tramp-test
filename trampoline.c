#include "tramp_test.h"

unsigned long regs[128][128] = {{0}};
extern unsigned long regs___, tramp_start, tramp_end ;

void top(void)
{
top_again:
   if (!regs[0][0]){
      printf("regs @ %p; [0][0]: %016lx\n", regs, regs[0][0]);
      printf("regs___ : %016lx\n", regs___);
      regs___ = 0;
      printf("regs___ : %016lx\n", regs___);
      printf("address of regs___: %p\n", &regs___);
      printf("address of tramp_start: %p\n", &tramp_start);
      printf("address of tramp_end: %p\n", &tramp_end);
   }
   void *position = &&top_again;
   printf("address of label top_again: %p\n", position);
   void *r = &regs[0][0];
   printf("address of regs[0][0]: %p\n", r);
   return;
}

void
land_here(void)
{
   void *start = 0
;
   void *end = 0;

   if (start || end) {
      ;
   }
   top();
   printf("landed here\n");
   
}
