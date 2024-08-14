#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int n,k;
    cin>>n>>k;
    string ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            char temp = (char)(j +97);
            ans+=temp;
        }
    }
    cout<< ans <<endl;
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