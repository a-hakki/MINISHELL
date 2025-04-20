#include <stdlib.h>
#include <stdio.h>


int main(int ac, char **av)
{
    unsigned char    c;
    c = (unsigned char)atoi(av[1]);
    printf("%i\n", c);
}