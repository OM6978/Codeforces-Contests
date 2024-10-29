#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

void solve()
{
    int N,M;
    cin>>N>>M;
    int S[N],A[M];
    for(int i=0;i<N;i++)cin>>S[i];
    for(int i=0;i<M;i++)cin>>A[i];

    sort(S,S+N);
    sort(A,A+M);

    int min=0,max=M-1,ans=0;
    for(int i=N-1;i>=0;i--)
    {
        ans+= abs(S[i]-A[min++]);
    }
    for(int i=0;i<N;i++)
    {
        if(ans - abs(S[i]-A[min-1]) + abs(S[i]-A[max])>=ans)ans+= abs(S[i]-A[max--]) - abs(S[i]-A[min---1]);
        else break;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}