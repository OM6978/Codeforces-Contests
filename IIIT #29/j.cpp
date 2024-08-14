#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    char ch='1';
    int stat=0,swit=0,num1=0,num2=0;
    for(int i=0;ch!='\n';i++)
    {
        scanf("%c",&ch);
        if(ch=='\n'){break;}
        if((ch==' '))
        {
            swit=1;
            continue;
        }
        else if(!((ch>=48)&&(ch<=57)))
        {
            printf("NaN\n");
            stat=1;
            break;
        }
        else
        {
            num1=(num1*10+((int)ch-48))*(swit==0)+num1*(swit==1);
            num2=(num2*10+((int)ch-48))*(swit==1)+num2*(swit==0);
        }
    }
    if(stat==0)
    {
        printf("%d\n",num1-num2);
    }
    return 0;
}