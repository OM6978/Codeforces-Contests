#include <bits/stdc++.h>
using namespace std;

#define int long long

int getperm(int i,int x,int y,vector<int> & ar)
{
    int N = ar.size();
    if(i == N)
    {
        return llabs(y - x);
    }

    int least = min(getperm(i+1,x+ar[i],y,ar),getperm(i+1,x,y+ar[i],ar));

    return least;
}

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    cout << getperm(0,0,0,ar) << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();
    
    return 0;
}