#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main()
{
    long double n,ans;
    scanf("%Lf",&n);
    ans=n/(2*(n-1));
    cout<<fixed<<setprecision(20)<<ans<<endl;
    return 0;
}