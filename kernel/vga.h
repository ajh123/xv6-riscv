#pragma once
#include "types.h"

static const uint8 BACKGROUND = 0x2f;
#define WIDTH 320
#define HEIGHT 200

typedef struct {
    uint32 port;
    uint8 index;
    uint8 val;
} vga_config_t;

extern vga_config_t vga_config_img_320_200[];
extern int std_palette[256];