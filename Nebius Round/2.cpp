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
    int n,k,d,w;
    scanf("%d %d %d %d",&n,&k,&d,&w);
    int arr[n],pos=-1,packs=0,packnum=k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>pos||packnum==0)
        {
            packs++;
            pos=arr[i]+w+d;
            packnum=k;
        }
        packnum--;
    }
    printf("%d\n",packs);
    }
    return 0;
}