#ifndef HASH_H
#define HASH_H
void hash(unsigned int*, unsigned int*);

unsigned int *init_K();

unsigned int *init_W(unsigned int*);

unsigned int ch(unsigned int, unsigned int, unsigned int);

unsigned int parity(unsigned int, unsigned int, unsigned int);

unsigned int maj(unsigned int, unsigned int, unsigned int);

unsigned int left_rotate(unsigned int, unsigned int);

#endif
