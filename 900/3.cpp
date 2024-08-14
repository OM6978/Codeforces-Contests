#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

int findleastsum(int N,int K)
{
    return (K*(K+1))/2;
}

int findgreatestsum(int N,int K)
{
    return K*N-((K-1)*K)/2;
}

void solve()
{
    int N,K,X;
    cin>>N>>K>>X;
    
    int least=findleastsum(N,K),most=findgreatestsum(N,K);

    if(X>=least&&X<=most)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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