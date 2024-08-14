#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    int n,x,p,x2;
    scanf("%d %d %d",&n,&x,&p);
    int arr[n],sum=0,term=0;
    for(int i=0;i<n;i++)
    {
        sum+=i+1;
        arr[i]=sum%n;
        if(i>p)
        {
            term=1;
            printf("No\n");
            break;
        }
        if((sum+x)%n==0)
        {
            term=1;
            printf("Yes\n");
            break;
        }
    }
    if(term==0)
    {
    x2=arr[n-1];
    int xdis=x2-x,point=-1;
    for(int i=0;i<n;i++)
    {
        if((n-arr[i])%xdis==0)
        {
            point=i;
            break;
        }
    }
    if(point==-1)
    {
        printf("No\n");
    }
    else
    {
        if(((n-arr[point])/xdis+1)*n+point>p)
        {
            printf("No\n"); 
        }
        else
        {
            printf("Yes\n");
        }
    }
    }
    return 0;
}