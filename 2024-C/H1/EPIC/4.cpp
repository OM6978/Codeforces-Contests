#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

int getmost(vector<int> & data)
{
    int M = data.size();
    int dp[M];
    for(int i=0;i<M;i++)dp[i] = -1;

    auto solvedp = [&](int in)
    {
        if(dp[in] != -1)return dp[in];
        
        int most = 1;
        for(int)
    };

    int most = 0;
    for(int i=1;i<M;i++)
    {
        most = max(most,solvedp(i));
    }

    return most;
}

void solve()
{
    int N;
    cin>>N;

    map<int,int> m1;
    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        m1[ar[i]]++;
    }

    vector<int> data;
    for(auto &[_,y] : m1)data.push_back(y);

    cout << getmost(data) <<endl;
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