#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;
    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    sort(ar,ar+N);

    int ans = 2*(ar[N-1] + ar[N-2] - ar[0] - ar[1]);
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