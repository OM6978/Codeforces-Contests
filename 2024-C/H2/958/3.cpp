#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '
#define int long long

void solve()
{
    int N;
    cin>>N;

    int K = __builtin_popcountll(N);
    if(K==1){cout<<1<<endl<<N<<endl;return;}
    cout<<K + 1<<endl;

    int comp = (1LL << 62);
    for(int i=0;i<K;i++)
    {
        while((N&comp) == 0)comp>>= 1;
        cout<< N-comp << sp;
        comp>>=1;
    }
    cout<<N<<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}