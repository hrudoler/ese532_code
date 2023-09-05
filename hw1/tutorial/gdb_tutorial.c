#include <stdio.h>
#include <stdlib.h>

void log_msg(char* string) {
    printf(string);
}

void my_broken_function()
{
    int a = 10;
    int *p = NULL;
    printf("Value of a is %d\n", a);
    *p = 1;
}

int main()
{
    log_msg("Welcome to the wonderful world of segfaults!\n");
    log_msg("Brace for impact! We are about to crash!\n");
    my_broken_function();
}