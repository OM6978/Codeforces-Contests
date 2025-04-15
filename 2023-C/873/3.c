#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

signed main()
{
    int Test;
    scanf("%d",&Test);
    for(int i=0;i<Test;i++)
    {
    int N,arr2pos=0;
    long long int sum=1;
    scanf("%d",&N);
    int arr1[N],arr2[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr2[i]);
    }
    qsort(arr1,N, sizeof(int), cmpfunc);
    qsort(arr2,N, sizeof(int), cmpfunc);
    for(int i=0;i<N;i++)
    {
        while((arr1[i]>arr2[arr2pos])&&(arr2pos!=N))
        {
            arr2pos++;
        }
        sum=((sum)*((long long)(arr2pos-i)))%1000000007;
    }
    printf("%lld\n",sum);
    }
    return 0;
}