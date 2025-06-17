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

    if(l1 == l2)return;

    if(rank[l1] > rank[l2])swap(l1,l2);

    P[l1]=l2;
    rank[l2]+= (rank[l1]==rank[l2]);
}

void solve()
{
    int N,M;
    cin>>N>>M;

    int P[N+1],rank[N+1];
    for(int i=0;i<N+1;i++)P[i] = i,rank[i] = 1;

    int num_components = N;
    while(M--)
    {
        int i,j;
        cin>>i>>j;

        union_s(i,j,P,rank);
        num_components--;
    }

    set<int> s;
    for(int i=1;i<=N;i++)
    {
        int par = get_a(i,P);
        s.insert(par);
    }

    vector<int> ans(s.begin(),s.end());

    cout << ans.size() - 1 << '\n';
    for(int i=0;i<ans.size()-1;i++)
    {
        cout << ans[i] << ' ' << ans[i+1] << '\n';
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/Om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/Om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();
    
    return 0;
}