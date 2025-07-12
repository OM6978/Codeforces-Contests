#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>
#define int long long

void solve()
{
    int N,K;
    cin>>N>>K;

    if(K&1){cout<<"NO"<<endl;return;}

    int tally=0;
    vector<int> ans;

    for(int i=1;i<=N/2;i++)
    {
        int comp = 2*(N-2*i+1);

        if(tally + comp > K)
        {
            ans.insert(ans.begin()+i-1,i);
            ans.insert(ans.begin()+i,N-i+1);
        }
        else
        {
            tally+=comp;
            ans.insert(ans.begin()+i-1,N-i+1);
            ans.insert(ans.begin()+i,i);
        }
    }

    if(N&1)ans.insert(ans.begin() + N/2, N/2 + (N&1));

    if(tally == K)
    {
        cout<<"YES"<<endl;
        for(int value: ans)cout<<value<<" ";
        cout<<endl;
    }
    else cout<<"NO"<<endl;
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