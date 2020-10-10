#include <stdint.h>
#include "waveforms.h"

uint8_t sineWave[] = {0x10, 0x11, 0x12, 0x14, 0x15, 0x17, 0x18, 0x19,
    0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1e, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1e, 0x1e, 0x1d, 0x1c,
    0x1b, 0x1a, 0x19, 0x18, 0x17, 0x15, 0x14, 0x12,
    0x11, 0x10, 0xe, 0xd, 0xb, 0xa, 0x8, 0x7,
    0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x1, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x2,
    0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0xa, 0xb,
    0xd, 0xe, 0x10};

uint8_t sawToothWave[] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
    0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e,
    0x1f, 0x00, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
    0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e,
    0x1f};

uint8_t triangularWave[] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
    0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e,
    0x1f, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x18,
    0x17, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11,
    0x10, 0xf, 0xe, 0xd, 0xc, 0xb, 0xa, 0x9,
    0x8, 0x8, 0x7, 0x6, 0x5, 0x4, 0x3, 0x2,
    0x1, 0x0};