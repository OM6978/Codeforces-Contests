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
    int N;
    scanf("%d",&N);
    int* arr1=(int*)calloc(sizeof(int),2*N+1),*arr2=(int*)calloc(sizeof(int),2*N+1);
    int temp,curr=-1,currmaxsum=0,maxx=-1;

    for(int i=0;i<N;i++)
    {
        scanf("%d",&temp);
        currmaxsum++;
        if(curr!=temp){currmaxsum=1;}
        curr=temp;
        arr1[curr]= (currmaxsum>arr1[curr])?currmaxsum:arr1[curr];
    }
    curr=-1;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&temp);
        currmaxsum++;
        if(curr!=temp){currmaxsum=1;}
        curr=temp;
        arr2[curr]= (currmaxsum>arr2[curr])?currmaxsum:arr2[curr];
        maxx= arr2[curr]+arr1[curr]?arr2[curr]+arr1[curr]:maxx;
    }

    printf("%d\n",maxx);
    arr1=NULL;
    arr2=NULL;
    }
    return 0;
}