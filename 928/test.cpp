#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int findsum(int currnum)
{
    int temp=1,ans=0;
    while(currnum!=0)
    {
        ans+=(currnum%10);
        currnum=currnum/10;
    }
    return ans;
}

void solve()
{
    int N;
    cin>>N;

    cout<< (N^2147483647)<<endl;
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