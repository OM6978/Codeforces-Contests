#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

void solve()
{
    int N,Q;
    cin>>N>>Q;

    int ar[N],prexor[N+1];
    prexor[0] = 0;

    map<int,vector<int>> mp;

    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        prexor[i+1] = ar[i]^prexor[i];
        mp[prexor[i+1]].push_back(i);
    }

    int l,r;
    for(int i=0;i<Q;i++)
    {
        cin>>l>>r;
        l--,r--;

        if(prexor[l] == prexor[r+1])
        {
            cout<<"YES"<<endl;
        }
        else
        {
            auto it2 = lower_bound(mp[prexor[r+1]].begin(),mp[prexor[r+1]].end(),l);

            if(it2 == mp[prexor[r+1]].end() || *it2 >= r){cout<<"NO"<<endl;continue;}

            auto it1 = lower_bound(mp[prexor[l]].begin(),mp[prexor[l]].end(),*it2);

            if(it1 == mp[prexor[l]].end() || *it1 >=r)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }

    cout<<endl;
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