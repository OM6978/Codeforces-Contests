#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Test;
    scanf("%d",&Test);
    for(int i=0;i<Test;i++)
    {
    long long int num;
    scanf("%lld",&num);

    double l=sqrt(2*num);

    long long int d=(long long int)l+1;

    if(d*d-d>num*2)
    {
        d--;
    }
    printf("%lld\n",d+((num*2-d*d+d)/2));
    }
    return 0;
}