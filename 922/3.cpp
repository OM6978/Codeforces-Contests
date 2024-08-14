#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

int maximizeee(int c,int r)
{

}

void solve()
{
    int a,b,r;
    cin>>a>>b>>r;

    if(a==b){cout<<"0"<<endl;return;}

    int first;
    for(int i=31;i>=0;i--){if((a>>i) & 1 > (b>>i)&1){first = i;break;}}

    
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