#include <bits/stdc++.h>
using namespace std;

#define int long long

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
    
    int ar[N],br[N],sum1=0,sum2=0;
    int most = 0;
    unordered_map<int,int,custom_hash> m1;

    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        sum1+=ar[i];

        m1[ar[i]]++;
        if(m1[ar[i]] >=2 && ar[i] >most)
            most = ar[i];

        br[i] = most;
        sum2+= br[i];
    }

    int ans = sum1,cr[N];
    m1.clear();
    most = 0,sum1 = 0,sum2 = 0;

    for(int i=0;i<N;i++)
    {
        sum1+=br[i];

        m1[br[i]]++;
        if(m1[br[i]] >=2 && br[i] >most)
            most = br[i];

        cr[i] = most;
        sum2+= cr[i];
    }
    ans+=sum1;

    for(int i=N-1;i;i--)
    {
        ans+=sum2;
        sum2-=cr[i];
    }

    cout<<ans<<'\n';
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