#include "Strings.h"

void string_print(char*str)
{
    int i;
    for(i=0;str[i];i++)
    {
        printf("%c",str[i]);

    }
    printf("\n\n");

}

void string_scan(char*str)
{
    int i=0;
    scanf(" %c",&str[i]);
    for(;str[i]!='\n';)
    {
        i++;
        scanf("%c",&str[i]);

    }
    str[i]=0;
}
