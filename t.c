#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    char *value = getenv(av[1]);
        printf("v = %s\n", value);
    return 0;
}
