#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

void solve()
{
    int N,M;
    cin>>N>>M;

    string a,b;
    cin>>a>>b;

    int j=0,k=0,flag=0;

    for(int i=0;i<a.size();i++)
    {
        while(b[j++]!=a[i] && flag==0)
        {
            if(j>=M)
            {
                flag=1;
                break;
            }
        }
        if(flag)break;
        k++;
    }

    cout<<k<<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}