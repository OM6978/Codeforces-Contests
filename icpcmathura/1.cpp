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
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    if(a==b)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    }
    return 0;
}