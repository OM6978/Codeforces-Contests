#include <bits/stdc++.h>
using namespace std;

int ask(int x,int y)
{
    cout << "? " << x << ' ' << y << '\n';

    int ret;
    cin>>ret;

    return ret;
}

int good(int mid1,int mid2)
{
    int x = ask(mid1,mid2);

    if(x == mid1*mid2)return 2;
    else if(x == (mid1)*(mid2+1))return 1;
    else return 0;
}

void solve()
{
    int l=1,r = 999;
    while(l+1<r)
    {
        int mid1 = l + (r - l)/3,mid2 = l + 2*(((double)(r-l))/(double)3);

        int stat = good(mid1,mid2);
        if(stat == 0)r = mid1;
        else if(stat == 1){l = mid1,r = mid2;}
        else l = mid2;
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