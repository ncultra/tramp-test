#include "tramp_test.h"

extern unsigned long _start;

extern void __attribute__((section("tramp"))) land_here(void);
extern uint64_t  __attribute__((section("tramp"))) saved_regs[];

int main(int argc, char **argv)
{
   struct reg_state *rstate = (struct reg_state *)saved_regs;
   printf("address of save_regs:       0x%08lx\n", (uint64_t)rstate);
   memset(rstate, 0x00, sizeof(struct reg_state) * 8);
   land_here();
   return 0;
}
