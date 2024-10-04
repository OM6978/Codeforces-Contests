#include <bits/stdc++.h>
using namespace std;

int get_a(int a,int* P)
{
    if(P[a] != a)P[a] = get_a(P[a],P);
    return P[a];
}

void union_s(int a,int b,int* P,int* rank)
{
    int l1 = get_a(a,P);
    int l2 = get_a(b,P);

    if(rank[l1] > rank[l2])l2 = l1 + l2 - (l1=l2);

    P[l1]=l2;
    rank[l2]+= (rank[l1]==rank[l2]);
}

void add_s()
{

}

void solve()
{
    int N,M;
    cin>>N>>M;

    int rank[N+1],P[N+1],exp[N+1];
    for(int i=1;i<=N;i++)rank[i]=1,P[i]=i,exp[i] = 0;

    for(int i=0;i<M;i++)
    {
        string s;
        cin>>s;

        int a,b;
        cin>>a>>b;

        if(s == "join")union_s(a,b,P,rank);
        else if(s == "add")add_s();
        else 
    }   
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}