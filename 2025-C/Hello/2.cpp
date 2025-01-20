#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,K;
    cin>>N>>K;

    map<int,int> freqz;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        freqz[ar[i]]++;
    }

    multiset<int> ss;
    for(auto &[_,y] : freqz)ss.insert(y);

    int lol = 0;
    int sum = 0;
    for(int x : ss)
    {
        sum += x;
        if(sum > K)break;
        lol++;
    }

    cout << max((int)ss.size() - lol,1LL) << '\n';
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