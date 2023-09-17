#pragma once
#include "types.h"
#include "riscv.h"

uint16 toggle_endian16(uint16);
uint32 toggle_endian32(uint32);
int time(int *);
int do_rand(unsigned long *);
int rand(void);