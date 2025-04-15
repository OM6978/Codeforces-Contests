#include <bits/stdc++.h>
using namespace std;

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

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<int> sort_ar(N);
    unordered_map<int,int,custom_hash> psss;

    for(int i=0;i<N;i++)
    {
        sort_ar[i] = ar[i];
        psss[ar[i]] = i;
    }

    sort(sort_ar.begin(),sort_ar.end());

    int guns = 1,last = psss[sort_ar[0]];

    for(int i=1;i<N;i++)
    {
        int bullt = sort_ar[i];
        int pos = psss[sort_ar[i]];
        if(pos > last)guns++;

        last = pos;
    }

    cout << guns << '\n';
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