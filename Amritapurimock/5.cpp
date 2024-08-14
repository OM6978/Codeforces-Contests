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
    int n;
    scanf("%d",&n);
    int arr[2*n],sum=0,aver,arr2[2*n];
    for(int i=0;i<2*n;i++)
    {
        scanf("%d",&arr[i]);
        arr2[i]=0;
        sum+=arr[i];
    }
    int stat=0;
    for(int i=0;i<2*n;i++)
    {
        stat=0;
        if(arr2[i]==1)
        {
            stat=1;
            continue;
        }
        for(int j=i+1;j<2*n;j++)
        {
            if((arr[i]+arr[j])*n==sum)
            {
                stat=1;
                arr2[i]=1;
                arr2[j]=1;
                break;
            }
        }
        if(stat==0){break;}
    }
    if(stat==0){printf("IMBALANCED\n");}
    else{printf("PERFECT\n");}
    }
    return 0;
}