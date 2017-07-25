#include <stdlib.h>
#include <stdio.h>
#include "message.h"
#include "hash.h"

unsigned int ch(unsigned int x, unsigned int y, unsigned int z)
{
    return ((x & y) | (~x & z));
}

unsigned int parity(unsigned int x, unsigned int y, unsigned int z)
{
    return (x ^ y ^ z);
}

unsigned int maj(unsigned int x, unsigned int y, unsigned int z)
{
    return ((x & y) | (x & z) | (y & z));
}

unsigned int left_rotate(unsigned int x, unsigned int c)
{
    return ((x << c) | (x >> (32 - c)));
}
