#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void line_writing(char str[], int level);
void build_array(char **ptr_to_array, char str[]);
void print_array(char **ptr_to_array, char str[]);

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
    char **array = malloc(sizeof(*array)*strlen(arg));       //line memory allocation
    for (int i=0; i<strlen(arg); i++)                        //column memory allocation
        array[i] = malloc(sizeof(**array)*2*strlen(arg)-1); 

    build_array(array, arg);
    print_array(array, arg);

    return 0;
}

void build_array(char **ptr_to_array, char str[])
{
    int line_size = strlen(str);
    int col_size = 2*strlen(str)-1;             //twice the length of the string to display less 1 character bc of the symetry
    int mid_col_pos = (col_size+1)/2;

    for (int line=0; line<line_size; line++)    //fill the array line by line
    {
        for (int col=0; col<col_size; col++)    //columns initialization to ' '
        {
            ptr_to_array[line][col] = ' ';
        }
        for (int cursor = 0; cursor<=line; cursor++)
        {
            ptr_to_array[line][mid_col_pos+cursor] = str[cursor];   //fill the right part of the array
            ptr_to_array[line][mid_col_pos-cursor] = str[cursor];   //fill the left part of the array
        }
    }
    return;
}

void print_array(char **ptr_to_array, char str[])
{
    for (int line=strlen(str)-1; line>=0; line--)
        printf("%s\n", ptr_to_array[line]);
}