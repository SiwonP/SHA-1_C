#include <stdlib.h>
#include <stdio.h>
#include "message.h"
#include "hash.h"

void hash(unsigned int *message, unsigned int *stamp) 
{

    unsigned int *K;
    K = init_K();

    unsigned int h0 = 0x67451201;
    unsigned int h1 = 0xefcdab89;
    unsigned int h2 = 0x98badcfe;
    unsigned int h3 = 0x10325476;
    unsigned int h4 = 0xc3d2e1f0;

    unsigned int a = h0;
    unsigned int b = h1;
    unsigned int c = h2;
    unsigned int d = h3;
    unsigned int e = h4;

    unsigned int *W;
    W = init_W(message);
    unsigned int tmp;
    unsigned int f;

    for (int i = 0; i < 80; i++) {
        if (i < 20) {
            f = ch(b, c, d);
        } else if ( i < 40 ) {
            f = parity(b, c, d);
        } else if (i < 60) {
            f = maj(b, c, d);
        } else {
            f = parity(b, c, d);
        }

        tmp = left_rotate(a, 5) + f + e + K[i] + W[i];
        e = d;
        d = c; 
        c = left_rotate(b, 30);
        b = a;
        a = tmp;
    }
    
    stamp[0] = h0 + a;
    stamp[1] = h1 + b;
    stamp[2] = h2 + c;
    stamp[3] = h3 + d;
    stamp[4] = h4 + e;

}

unsigned int *init_K()
{
    static unsigned int K[80] = {0};
    for (int i = 0; i < 80; i++) {
        if (i < 20) {
            K[i] = 0x5a827999;
        } else if (i < 40) {
            K[i] = 0x6ed9eba1;
        } else if (i < 60) {
            K[i] = 0x8f1bbcdc;
        } else {
            K[i] = 0xca62c1d6;
        }
    }
    return K;
}


unsigned int *init_W(unsigned int *message)
{
    static unsigned int W[80] = {0};

    for (int i = 0; i < 16; i++) {
        if (i < 16) {
            W[i] = message[i];
        } else {
            W[i] = left_rotate((W[i-3] ^ W[i-8] ^ W[i-14] ^ W[i-16]), 1);
        }
    }

    return W;

}

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
