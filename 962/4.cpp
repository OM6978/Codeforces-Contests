#include <bits/stdc++.h>
using namespace std;

#define int long long

pair<int,int> solvequad(double a,double b,double c)
{
    pair<int,int> ans;
    
    ans.first = (-b - sqrt(b*b - 4*a*c))/(2*a);
    ans.second = (-b + sqrt(b*b - 4*a*c))/(2*a);

    return ans;
}

void solve()
{
    int n,x;
    cin>>n>>x;

    int minii = min(n,x),ans = 0;
    for(int c = 1;c<minii-2;c++)
    {
        if(x*x >= 4*n + 3*c*c + c*x)
        {
            int l1 = (x-1-c),l2 = ((n-c)/(1+c));
            pair<int,int> bs = solvequad(1,c-x,n+c*c+c*x);

            if(l1 >= l2)
            {
                ans+= bs.first*
            }
        }
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}