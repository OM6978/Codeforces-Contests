#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>
#define int long long

int findmaxscore(int pos,int* elems,int* perms,int N,int K)
{
    vector<int> travelled(N,0);

    int prev=0,max=0,turns=0;
    for(int i=pos-1;travelled[i]!=1 && turns<K;i = perms[i]-1)
    {
        int hope = (K-turns)*elems[i] + prev;
        if(hope > max) max = hope;

        turns++;prev += elems[i];
        travelled[i]=1;
    }

    return max;
}

void solve()
{
    int N,K,Pb,Ps;
    cin>>N>>K>>Pb>>Ps;

    int elems[N],perms[N];

    for(int i=0;i<N;i++)cin>>perms[i];
    for(int i=0;i<N;i++)cin>>elems[i];

    int sc1 = findmaxscore(Pb,elems,perms,N,K);
    int sc2 = findmaxscore(Ps,elems,perms,N,K);

    // cout<<sc1<<spc<<sc2<<endl;

    if(sc1 > sc2)cout<<"Bodya"<<endl;
    else if(sc1 < sc2)cout<<"Sasha"<<endl;
    else cout<<"Draw"<<endl;
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