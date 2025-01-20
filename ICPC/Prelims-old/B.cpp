#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,d,l;
    cin>>n>>d>>l;

    int N = n;
    vector<vector<int>> tree(N+1,vector<int>());

    for(int i=1;i<=d;i++)
    {
        tree[i].push_back(i+1);
    }

    n-=d+1;
    l-=2;

    int maxd = d/2;
    int in = d/2 + 1;
    int last = in,curr = d+2;

    while(n>0 && l>0 && n >= l)
    {
        l--;
        int tomin = min(maxd,n-l);
        for(int i=0;i<tomin;i++)
        {
            tree[last].push_back(curr);
            last = curr++;
        }
        n-=tomin;
        last = in;
    }

    if(l!=0 || n!=0)
    {
        cout << -1 << '\n';
        return;
    }

    for(int i=1;i<=N;i++)
    {
        for(int v : tree[i])cout << i << ' ' << v << '\n';
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}