#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int convert(char str[]);
long int power(int a, int b);

char *get_first_arg(int argc, char *argv[])
{
    if (argc <2)
    {
        printf("no argument\n\n");
        exit(0);
    }
    return (argv[1]);
}

long int main(int argc, char *argv[])
{
    char *arg = get_first_arg(argc, argv);

    long int ret_val=convert(arg);

    if (ret_val == -1)
        printf("Please enter only integer number\n\n");

    return ret_val;
}

long int convert(char str[])
{
    long int result = 0;
    long int conv_value_array[strlen(str)];

    for (int index=0; str[index]!=0; index++)
    {
        if (str[index]>=0x30 && str[index]<=0x39)
        {
            conv_value_array[index] = str[index]-0x30;
        }
        else
        {
            result = -1;
            break;
        }
    }
    if (result!=-1)
    {
        for (int index=0; index<=strlen(str)-1; index++)
            result = result + conv_value_array[index]*power(10,(strlen(str)-1-index));
    }
    return result;
}


long int power(int a, int b)
{
    long int result=1;
    for (int i=1; i<=b; i++)
        result = result*a;
    return result;
}