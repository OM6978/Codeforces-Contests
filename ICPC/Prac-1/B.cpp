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
    int N,K;
    cin>>N>>K;

    unordered_map<int,int,custom_hash> mp;
    for(int i = 0; i < N; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }

    priority_queue<int,vector<int>> pq;
    for(auto [_,y]:mp)
    {
        pq.push(y);
    }

    for(int i=0;i<min(N,K);i++)
    {
        int curr = pq.top();
        pq.pop();

        if(curr-1 > 0)pq.push(curr-1);
        pq.push(1);
    }

    vector<int> vals;
    while(pq.size())
    {
        vals.push_back(pq.top());
        pq.pop();

        // cout << vals.back() << '\n';
    }

    int sum = 0,ans = 0;
    for(int x : vals)sum+=x;

    for(int x : vals)
    {
        ans += (sum-x)*x;
        sum-=x;
    }

    cout << ans << '\n';
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
    //     freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}