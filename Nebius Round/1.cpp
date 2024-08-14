#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    int Test;
    scanf("%d",&Test);
    for(int i=0;i<Test;i++)
    {
    int a,b,A,B;
    scanf("%d %d",&A,&B);
    a=abs(A);
    b=abs(B);
    if(a>b)
    {
        printf("%d\n",2*b+2*(a-b)-(a!=b));
    }
    else
    {
        printf("%d\n",2*a+2*(b-a)-(a!=b));
    }
    }
    return 0;
}