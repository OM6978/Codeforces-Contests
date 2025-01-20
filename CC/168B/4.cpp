#include <bits/stdc++.h>
using namespace std;

int dothething(int i,int * ar,int N,int* prexor)
{
    if(i>=N)return 0;
    int x = ar[i];

}

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    int prexor[N];
    prexor[0] = ar[0];

    map<int,vector<int>> mm;
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        if(i!=0)prexor[i] = prexor[i-1]^ar[i];
    }

    int vis[N];
    for(int i=0;i<N;i++)
    {

    }
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