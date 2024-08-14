#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '
#define int long long

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    cin>>ar[0];

    map<int,int> g;
    int num = 0;
    for(int i=1;i<N;i++)
    {
        cin>>ar[i];
        if(ar[i] < ar[i-1])
        {
            g[ar[i-1] - ar[i]]++;
            num++;
            ar[i] = ar[i-1];
        }
    }

    int ans = 0,curr = 0;
    for(auto &[x,y] : g)
    {
        ans+=(num+1)*(x - curr);
        curr+= (x-curr);
        num-= y;
    }

    cout<<ans<<endl;
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