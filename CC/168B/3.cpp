#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    map<int,tuple<int,int,int>> mm;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        auto &[a,b,c] = mm[ar[i]];

        a++;
        if(a==1)b=i;
        c = i;
    }

    vector<pair<int,int>> subs;
    for(auto &[x,t] : mm)
    {
        auto &[a,b,c] = t;
        if(a > 1)
        {
            subs.push_back({b,c});
        }
    }

    sort(subs.begin(),subs.end());

    vector<pair<int,int>> subs2;

    if(subs.size())
    {
        int M = subs.size();
        subs2.push_back(subs[0]);
        for(int i=1;i<M;i++)
        {
            auto [l,r] = subs[i];
            auto &[ll,lr] = subs2.back();
            if(l<lr)
            {
                if(r > lr)
                    lr = r;
            }
            else
            {
                subs2.push_back(subs[i]);
            }
        }
    }

    int ops = 0;
    for(auto [l,r] : subs2)
    {
        set<int> us;
        for(int i=l;i<=r;i++)
        {
            us.insert(ar[i]);
        }
        ops+= us.size();
        us.clear();
    }

    cout << ops << '\n';
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