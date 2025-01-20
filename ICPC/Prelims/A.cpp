#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,K;
    cin>>N>>K;

    set<pair<int,int>> sp;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        sp.insert({ar[i],i});
    }

    for(int i=0;i<=30;i++)
    {
        int parry = (1<<i);
        int tomatch = K&parry;

        vector<pair<int,int>> nums(sp.begin(),sp.end());
        for(auto [val,ind]:nums)
        {
            int num = val & parry;
            if(tomatch > 0 && num == 0)
            {
                sp.erase({val,ind});
            }
        }
    }

    int bitandd = (1<<30) - 1 + (1<<30);
    for(auto &[x,y] : sp)
    {
        bitandd = bitandd & x;
    }

    if(bitandd != K)
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES\n";
        cout << sp.size() << '\n';
        for(auto &[x,y] : sp)
        {
            cout << y + 1 << ' ';
        }
        cout << '\n';
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