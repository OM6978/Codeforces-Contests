#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    map<int,int> mp;

    int N;
    cin>>N;
    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        mp[ar[i]]++;
    }

    
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