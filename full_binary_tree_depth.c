#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[20];
    int count=0;
    scanf("%s",a);
    int l=strlen(a);
    for(int i=0;i<l;i++)
    {
        if(a[i]=='n')
        {
            count++;
        }
    }
    printf("%d",count);
}
