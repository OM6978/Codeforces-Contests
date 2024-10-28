#include <bits/stdc++.h>
using namespace std;

int get_problem(int i,int* ar,int N)
{
    return (ar[i] == ar[i+1]) + (ar[N-i-1] == ar[N-i-2]);
}

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    int ans = 0;
    for(int i=N/2-1;i>=0;i--)
    {
        int problem = get_problem(i,ar,N);

        swap(ar[i],ar[N-i-1]);
        int p2 = get_problem(i,ar,N);

        if(p2>=problem)swap(ar[i],ar[N-i-1]);
    }

    for(int i=0;i<N-1;i++)
    {
        if(ar[i] == ar[i+1])ans++;
    }

    cout << ans << '\n';
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