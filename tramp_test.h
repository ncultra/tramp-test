#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <getopt.h>
#include <limits.h>

struct reg_state {
   uint64_t gp_regs[32];
   uint64_t cr_regs[6];
};
