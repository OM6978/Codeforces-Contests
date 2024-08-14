#include <bits/stdc++.h>
using namespace std;

int ask(int x,int y)
{
    cout << "? " << x << ' ' << y << '\n';

    int ret;
    cin>>ret;

    return ret;
}

bool good(int mid)
{
    int x = ask(1,mid);
    return (x == mid + 1);
}

void solve()
{
    int l=1,r = 999;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(good(mid))r = mid;
        else l = mid;
    }

    cout<< "! " << r << '\n';
}

signed main()
{    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}