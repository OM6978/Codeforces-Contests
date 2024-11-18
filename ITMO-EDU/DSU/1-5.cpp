#include <bits/stdc++.h>
using namespace std;

int get_a(int a,int* P)
{
    if(P[a] != a)return get_a(P[a],P);
    return P[a];
}

void union_s(int a,int b,int* P,int* rank)
{
    int l1 = get_a(a,P);
    int l2 = get_a(b,P);

    if(l1 == l2)return;
    if(rank[l1] > rank[l2])swap(l1,l2);

    P[l1]=l2;
    rank[l2]+= (rank[l1]==rank[l2]);
}

int find_time(int a,int* P,int M,vector<int> & time)
{
    static int root = get_a(1,P);

    if(time[a]!=M)return time[a];
    else if(get_a(a,P) == root)return time[a] = find_time(P[a],P,M,time);
    else return 0;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> hands(N+1,vector<int>(3));
    for(int i=1;i<=N;i++)
    {
        cin>> hands[i][1] >> hands[i][2];
    }

    int inp[M][2];
    vector<vector<int>> currhands = hands;
    for(int i=0;i<M;i++)
    {
        cin>>inp[i][0]>>inp[i][1];
        currhands[inp[i][0]][inp[i][1]] = -1;
    }

    int P[N+1],rank[N+1];
    for(int i=1;i<=N;i++)P[i]=i,rank[i]=1;
    
    for(int i=1;i<=N;i++)
    {
        auto & v = currhands[i];
        if(v[1]!=-1)union_s(i,v[1],P,rank);
        if(v[2]!=-1)union_s(i,v[2],P,rank);
    }

    vector<int> ans(N+1,-1);
    for(int i=1;i<=N;i++)
    {
        int root = get_a(1,P);
        int p = get_a(i,P);

        if(root!=p)ans[i] = M;
    }

    for(int i=M-1;i>=0;i--)
    {
        int root = get_a(1,P);
        int monk = inp[i][0],hand = inp[i][1];
        if(hands[monk][hand]==-1)continue;

        int p1 = get_a(monk,P),p2 = get_a(hands[monk][hand],P);
        
        if(p1 == root && p2!=root)ans[hands[monk][hand]] = i;
        else if(p2 == root && p1!=root)ans[monk] = i;

        union_s(monk,hands[monk][hand],P,rank);
    }

    for(int i=1;i<=N;i++)
    {
        cout << find_time(i,P,M,ans) << '\n';
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