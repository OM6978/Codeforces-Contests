#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;

    v_int arr(N);
    int sum=0,negs=0;

    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        negs+=(arr[i]<0);
        sum+=(arr[i]=abs(arr[i]));
    }

    if((negs&1))cout<<sum - 2*(*min_element(arr.begin(),arr.end()))<<endl;
    else cout<<sum<<endl;
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