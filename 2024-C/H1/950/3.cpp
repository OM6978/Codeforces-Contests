#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve()
{
    int N;
    cin>>N;

    unordered_map<long long, int, custom_hash> needed,all;

    int ar[N],br[N],total=0;
    for(int i=0;i<N;i++)cin>>ar[i];

    for(int i=0;i<N;i++)
    {
        cin>>br[i];
        all[br[i]]++;

        if(ar[i]!=br[i])
        {
            needed[br[i]]++;
            total++;
        }
    }

    int M;
    cin>>M;

    int dr[M],anyone=0;
    for(int i=0;i<M;i++)
    {
        cin>>dr[i];

        if(anyone && all[dr[i]]!=0)anyone=0;
        else if(total==0 && all[dr[i]]==0)anyone = 1;

        else if(needed[dr[i]]!=0)
        {
            needed[dr[i]]--;
            total--;
        }
    }

    if(anyone == 0 && total==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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