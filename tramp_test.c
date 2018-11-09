#include "tramp_test.h"

extern unsigned long _start;

extern void __attribute__((section("tramp"))) land_here(void);
extern unsigned long __attribute__((section("tramp"))) tramp_start;
extern unsigned long __attribute__((section("tramp"))) tramp_end;
int main(int argc, char **argv)
{
   land_here();
   return 0;
}
