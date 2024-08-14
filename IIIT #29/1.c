#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,g1,s1,b1,g2,s2,b2;
char str1[10000],str2[100000];

int main()
{
    scanf("%d",&n);
    scanf("%d %d %d ",&g1,&s1,&b1);
    gets(str1);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d %d ",&g2,&s2,&b2);
        gets(str2);
        if((g2>g1)||((g1==g2)&&(s2>s1))||((g1==g2)&&(s1==s2)&&(b2>b1)))
        {
            g1=g2;
            s1=s2;
            b1=b2;
            strcpy(str1,str2);
        }
    }
    printf("%s\n",str1);
    return 0;
}