#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arr_size 1000

void print_array(char array[arr_size][arr_size]);
void format(char array[arr_size][arr_size]);
void stock_truncated_str(char store_array[arr_size][arr_size], char str[]);

char *get_first_arg(int argc, char *argv[])
{
    if (argc <2)
    {
        printf("no argument\n\n");
        exit(0);
    }
    return (argv[1]);
}

int main(int argc, char *argv[])
{
    char *arg = get_first_arg(argc, argv);

    char array[arr_size][arr_size] = { 0 };

    if(strlen(arg)<=arr_size)                   //to avoid having a bigger string than the array can stock
    {
        stock_truncated_str(array,arg);         //stock the truncated string in an array
        format(array);
        print_array(array);
    }
    else printf("Too much characters in the argument\n\n");

    return 0;
}

void stock_truncated_str(char store_array[arr_size][arr_size], char str[])
{
    int line=0;
    int col=0;

    for (int index=0; index<strlen(str); index++)
    {
        if (str[index]==0x20)               //switch line and reset column when there is a space in the string
        {
            col = 0;
            line++;
        }
        else                                //stock character by character in the array
        {
            store_array[line][col] = str[index];
            col++;
        }
    }
}

void format(char array[arr_size][arr_size])
{
    for (int line=0; array[line][0]!=0; line++)                 //line by line until encounters an empty case
    {
        if (array[line][0]>=0x61 && array[line][0]<=0x7A)       //if the first character is a lowercase letter, then make it uppercase
            array[line][0] = array[line][0]-0x20;
    }
}

void print_array(char array[arr_size][arr_size])                //print array line by line until encounters an empty case
{
    for (int line=0; array[line][0]!=0; line++)
        printf("%s\n", array[line]);
}