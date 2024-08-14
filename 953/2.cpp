#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>
#define int long long

int qfunk(double x,int a,int b,int n)
{
    int x1 = floor(x);
    int x2 = ceil(x);

    int p1 = x1*(b-a) + (x1 - x1*x1)/2 + n*a;
    int p2 = x2*(b-a) + (x2 - x2*x2)/2 + n*a;

    return max(p1,p2);
}

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;

    int x = min(n,b);
    double comp = (double)(b - a) + (double)0.5f;

    int prof;

    if(comp < 0)prof = qfunk(0,a,b,n);
    else if(comp > x)prof = qfunk(x,a,b,n);
    else prof = qfunk(comp,a,b,n);

    cout<<prof<<endl;
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