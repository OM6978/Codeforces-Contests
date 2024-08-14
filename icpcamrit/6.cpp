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
    int arr[n],last=0,arrans[3*n],length=-1,temp;
    scanf("%d",&arr[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]<arr[i-1])
        {
            temp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;
            arrans[last]=i-1;
            arrans[last+1]=i;
            arrans[last+2]=i-1;
            last+=3;
            length=last;
        }
    }
    printf("%d\n",last);
    if(length!=-1)
    {
    for(int i=0;i<last;i++)
    {
        printf("%d %d\n",arrans[i]+1,arrans[i]+2);
    }
    }
    }
    return 0;
}