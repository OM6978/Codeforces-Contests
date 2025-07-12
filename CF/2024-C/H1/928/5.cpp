#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

void solve()
{
    int N,K;
    cin>>N>>K;

    int mult = 1,till=0,lol;
    while(till<K)
    {
        lol = N/(2*mult);
        till+= N/(2*mult) + ((N-mult)>=lol*2*mult);
        mult=mult*2;
    }

    mult=mult/2;
    till-=((N-mult)>=lol*2*mult) + (N/(mult*2));

    int temp = K - till;
    int ans = mult*2*temp - mult;

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