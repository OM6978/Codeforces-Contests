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
    int elem=N+1;
    int arr[N];
    for(int i=0;i<N;i++)
    {scanf("%d",&arr[i]);}
    for(int i=0;i<N;i++)
    {
        printf("%d ",elem-arr[i]);
    }
    printf("\n");
    }
    return 0;
}