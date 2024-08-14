#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int Test;
    scanf("%d",&Test);
    for(int i=0;i<Test;i++)
    {
    int isperfect=0,N,sum=0,temp;
    scanf("%d",&N);
    int ansmultiplier;
    sum=(N*(N+1))/2;
    if(sum%N==0)
    {
        sum=0;
    }
    else
    {
        sum=sum%N;
    }
    ansmultiplier=sum;
    for(int i=0;i<N-1;i++)
    {
        if(ansmultiplier!=i+1)
        {
            printf("%d ",i+1);
        }
        else
        {
            printf("%d ",(i+1)*2);
        }
    }
    if(ansmultiplier!=N)
    {
        printf("%d\n",N);
    }
    else
    {
        printf("%d\n",N*2);
    }
    }
    return 0;
}