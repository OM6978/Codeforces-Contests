#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,K;
    cin>>N>>K;

    vector<pair<int,int>> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i].second;
    }

    for(int i=0;i<N;i++)
    {
        cin>>ar[i].first;
        ar[i].first = abs(ar[i].first);
    }

    sort(ar.begin(),ar.end());

    int rem = 0,last = 0;
    for(int i=0;i<N;i++)
    {
        rem+= (ar[i].first - last)*K;
        last = ar[i].first;

        rem -= ar[i].second;

        if(rem < 0)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}