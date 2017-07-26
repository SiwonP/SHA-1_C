#include <stdlib.h>
#include <stdio.h>
#include "message.h"
#include "hash.h"

int main(int argc, char *argv[])
{
    unsigned int *message;

    if (argc < 2) {
        printf("usage : %s <string>", argv[0]);
        return 1;
    }
    message = complete(argv[1]);
    unsigned int stamp[5];
    hash(message, stamp);

    display_stamp(stamp);

    return 1;
}
