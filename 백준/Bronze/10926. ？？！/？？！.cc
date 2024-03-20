#include <stdio.h>
#include <string.h>

int main()
{
    char id[50];
    const char *a1 = "\?\?!";

    scanf("%s",id);
    strcat(id,a1);
    printf("%s\n",id);
    
    return 0;
}