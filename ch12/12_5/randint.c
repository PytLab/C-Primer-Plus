#include <stdio.h>
#include <time.h>

static unsigned long next = 1;  /*种子*/

int randint(unsigned int n)
{
    unsigned long randn;
    next = next*1103515245 + 12345;
    randn = (unsigned long)(next/65526) % 32768;
    return randn % n + 1;
}

void srandint(unsigned int n)
{
    next = n;
}
