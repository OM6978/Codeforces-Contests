#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

struct Job 
{ 
    int id;
    int dead;
    int profit;
};

static int comparator(const void* j,const void* i)
{
    return ((Job*)j)->profit - ((Job*)i)->profit;
}

void solve()
{
    int N;
    cin>>N;

    Job ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i].id;
        cin>>ar[i].dead;
        cin>>ar[i].profit;
    }

    qsort(ar,N,sizeof(Job),comparator);

    for(int i=0;i<N;i++)cout<<ar[i].profit<<spc;
    cout<<endl;
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