#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

void solve()
{
    int N;
    cin>>N;

    int ar[N],max1=0,max2=0;
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        if(ar[i] > max1)
        {
            max2 = max1;
            max1 = ar[i];
        }
        else if(ar[i] > max2)max2 = ar[i];
    }

    cout<<max1+max2<<endl;
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