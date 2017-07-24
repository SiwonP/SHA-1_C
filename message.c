#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int *complete(char *input) {
    static unsigned int message[16] = {0};
    int bufferSize = 0;
    unsigned int buffer = 0;

    long long sizeMessage = 0;

    /*Size of the message coded 
     * in 64 bits */
    long long size = strlen(input) * 8;

    int i = 0;
    int j = 0;

    unsigned int tmp = 0;

    while (input[i] != 0) {
        /* Use of the tmp
         * to append to the 
         * beginning and not
         * to the end
         * ie reading in Little Endian */
        tmp = input[i];
        tmp = tmp << (bufferSize * 8);
        bufferSize++;
        buffer = buffer | tmp;
        i++;
        
        if (bufferSize == 4) {
            message[j] = buffer;
            buffer = 0;
            bufferSize = 0;
            sizeMessage = sizeMessage + 32;
            j++;
        }
    }

    /* Adding a bit 1 
     * to the current buffer (even if its 
     * empty) still with 
     * the reading in little endian
     * (that's why i use the tmp
     * int) */
    unsigned char one = 1;
    one = one << 7;
    tmp = one;
    tmp = tmp << (bufferSize * 8);
    buffer = buffer | tmp;

    message[j] = buffer;
    sizeMessage = sizeMessage + 32;
    j++;
    bufferSize = 0;
    buffer = 0;

    while (sizeMessage < 448) {
        message[j] = 0;
        sizeMessage = sizeMessage + 32;
        j++;
    }


    unsigned int sizePart1 = 0;
    unsigned int sizePart2 = 0;

    /* storing the size of the
     * initial message in bits
     * in 2 x 32 bits (since
     * it's coded in 64 bits) */
    sizePart1 = (unsigned int)size;
    sizePart2 = size >> 32;


    message[j] = sizePart1;
    j++;
    sizeMessage = sizeMessage + 32;
    message[j] = sizePart2;
    j++;
    sizeMessage = sizeMessage + 32;

    return message;
}

void display_unsigned_long(unsigned int n) {
    unsigned char a = (unsigned char)n;
    unsigned char b = n >> 8;
    unsigned char c = n >> 16;
    unsigned char d = n >> 24;
    printf("%2.2x", a);
    printf("%2.2x", b);
    printf("%2.2x", c);
    printf("%2.2x", d);
}

void display_stamp(unsigned int *stamp) {
    for (int i = 0; i < 4; i++) {
        display_unsigned_long(stamp[i]);
    }
    printf("\n");
}
