#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int pair<int>
#define int long long

void solve()
{
    int N,C;
    cin>>N>>C;
    int S[N],P=0,Q=(-1)*C;
    for(int i=0;i<N;i++)
    {
        cin>>S[i];
        P+=S[i];
        Q+=S[i]*S[i];
    }
    long double P_not=((long double)P)/(long double)N,Q_not=(long double)Q/(long double)N;
    long double output=(sqrt(P_not*P_not-Q_not)-P_not)/(long double)2;
    cout<<lround(output)<<endl;
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