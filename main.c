#include <stdlib.h>
#include <stdio.h>
#include "message.h"

int main(int argc, char *argv[])
{
    unsigned int *message;

    if (argc < 2) {
        printf("usage : %s <string>", argv[0]);
        return 1;
    }
    message = complete(argv[1]);
    return 1;
}
