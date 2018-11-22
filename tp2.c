#include <stdio.h>
#include <stdlib.h>

char *upper(char *s)
{
    int index = 0;
    while (s[index] != 0)
    {
        printf("%c\n", s[index]);
        if (s[index] >= 0x61 && s[index] <= 0x7A)
            s[index] = s[index] - 0x20;
        index++;
    }

    return s;
}