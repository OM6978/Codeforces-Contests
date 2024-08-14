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

    int arr1[N],arr2[M];
    for(int i=0;i<N;i++)cin>>arr1[i];
    for(int i=0;i<M;i++)cin>>arr2[i];

    int j = 0,count = 0,flag = 0,curreq = 0,first = 0;
    for(int i=0;i<N;i++)
    {
        while(arr1[i]>arr2[j] && flag == 0)
        {
            first = 0;curreq = 0;
            if(++j==M)flag=1;
        }
        if(arr1[i] == arr2[j] && first == 0 && flag == 0)
        {
            while(arr1[i] == arr2[j] && flag == 0)
            {
                curreq++;
                if(++j==M)flag=1;
            }
            j--;first =1;
        }
        if(arr1[i] == arr2[j])count+= curreq;
    }

    cout<<count<<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}