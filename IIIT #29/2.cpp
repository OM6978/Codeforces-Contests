#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

int sumfinder(int num)
{
    int sum=1;
    double sq=sqrt(num);
    for(int i=2;((double)i)<=sq;i++)
    {
        if(num%i==0){sum+=i+num/i;}
    }
    if((int)sq*(int)sq==num)
    {
        sum-=sq;
    }
    return sum;
}
int main()
{
    int n,temp;
    scanf("%d",&n);
    int arr[n],sum;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        sum=sumfinder(temp);
        if(sum>temp){arr[i]=0;}
        if(sum<temp){arr[i]=1;}
        if(sum==temp){arr[i]=2;}
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0){printf("abundant\n");}
        if(arr[i]==1){printf("deficient\n");}
        if(arr[i]==2){printf("perfect\n");}
    }
    return 0;
}