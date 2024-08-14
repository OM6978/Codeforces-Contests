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
    int n,temp,dis=0,lik=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        if(temp>0){lik++;}
        else{dis++;}
    }
    int stat=0,lik2=lik;
    for(int i=0;i<n-1;i++)
    {
        if(lik2!=0)
        {
            printf("%d ",++stat);
            lik2--;
        }
        else
        {
            printf("%d ",--stat);
        }
    }
    printf("%d\n",lik-dis);
    stat=0;
    int lik3=lik,dis3=dis,cond=0;
    for(int i=0;i<n-1;i++)
    {
        if(dis3!=0)
        {
            if(cond==0)
            {
                printf("1 ");
                lik3--;
                cond++;
            }
            else
            {
                printf("0 ");
                dis3--;
                cond--;
            }
        }
        else
        {
            if(lik3!=0)
            {
                printf("%d ",++stat);
                lik3--;
            }
        }
    }
    printf("%d\n",lik-dis);
    }
    return 0;
}