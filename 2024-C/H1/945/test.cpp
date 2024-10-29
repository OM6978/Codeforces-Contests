#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

int power(int x, int y, int p)
{
    int res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
        res = (res * x)%p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}

bool good(int mid,int n,int m)
{
    if(power(mid,n,(int)(1e9+7)) >= m)return true;
    else return false;
}

int NthRoot(int n, int m)
{
    int l = 0,r = m;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(good(mid,n,m))r = mid;
        else l = mid;
    }

    return r;
}

void solve()
{
    cout<<NthRoot(3,27)<<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}