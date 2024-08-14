#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>
#define int long long

void rrremove(vector<int>& v,int K)
{
    int s1=0,s2=0;

    for(int i=0;i<v.size();i+=2)
    {
        s1+= (v[i+1] - v[i])/K;
    }

    for(int i=1;i<v.size();i+=2)
    {
        s2+= (v[i+1] - v[i])/K;
    }

    int pos=0,currs1=0,currs2=s2,low=s2;
    for(int i=1;i<v.size();i++)
    {
        if(i&1)
        {
            currs2 -= (v[i+1]-v[i])/K - (v[i+1]-v[i-1])/K;
        }
        else
        {
            currs1+= (v[i-1] - v[i-2])/K;
            currs2-= (v[i] - v[i-2])/K;
        }

        if(currs1+currs2 < low)
        {
            low = currs1+currs2;
            pos = i;
        }
    }

    v.erase(v.begin()+pos);
}

void solve()
{
    int N,K;
    cin>>N>>K;

    map<int,vector<int>> m1;

    int ar[N],check=(N&1);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        m1[ar[i]%K].push_back(ar[i]);
    }

    int ans=0;

    for(auto &[x,v]:m1)
    {
        sort(v.begin(),v.end());

        if(v.size()&1)
        {
            if(check)
            {
                check=0;
                rrremove(v,K);
            }
            else
            {
                cout<<-1<<endl;
                return;
            }
        }

        for(int i=0;i<v.size();i+=2)
        {
            ans+= (v[i+1] - v[i])/K;
        }
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