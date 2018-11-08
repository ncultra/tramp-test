#include "tramp_test.h"

extern unsigned long _start;

extern void __attribute__((section("tramp"))) land_here(void);
extern unsigned long __attribute__((section("tramp"))) tramp_start;
extern unsigned long __attribute__((section("tramp"))) tramp_end;
int main(int argc, char **argv)
{
   printf("hello, world\n");
   land_here();
   printf("tramp end, tramp start: %016lx, %016lx\n", tramp_end, tramp_start);
   printf("land here: %p\n", land_here);
   printf("main: %p\n", (void *)main);
   return 0;
}
