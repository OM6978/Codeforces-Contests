#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    long long int Test;
    scanf("%lld",&Test);
    for(long long int i=0;i<Test;i++)
    {
    long long int n;
    scanf("%lld",&n);
    long long int arr[n],min1,min2,sum=0,temp;
    for(long long int i=0;i<n;i++){scanf("%lld",&arr[i]);}
    for(long long int i=0;i<n-1;i++)
    {
        min1=(arr[i]>=arr[i+1])*arr[i+1]+((arr[i]<arr[i+1])*arr[i]);
        min2=(arr[i]>=arr[i+1])*arr[i]+((arr[i]<arr[i+1])*arr[i+1]);
        sum+=min1^min2;
        for(long long int j=i+2;j<n;j++)
        {
            if(arr[j]<min2)
            {
                min2=arr[j];
                if(min2<min1)
                {
                    temp=min2;
                    min2=min1;
                    min1=temp;
                }
            }
            sum+=min1^min2;
        }
    }
    printf("%lld\n",sum);
    }
    return 0;
}