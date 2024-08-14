#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    int n,op=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[i]){op++;}
        }
    }
    printf("%d\n",op);
    return 0;
}