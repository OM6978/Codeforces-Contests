#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    int ar[N],max_o = -1,max_e = -1,odd = 0,even = 0;
    vector<int> eves;

    for(int i=0;i<N;i++)
    {
        cin>>ar[i];

        if(ar[i]&1)
        {
            odd++;
            max_o = max(max_o,ar[i]);
        }
        else
        {
            even++;
            max_e = max(max_e,ar[i]);
            eves.push_back(ar[i]);
        }
    }

    if(even == 0 || odd == 0){cout<< 0 << '\n'; return;}

    sort(eves.begin(),eves.end());

    int flag = 0,curr = max_o;
    for(int x : eves)
    {
        if(x > curr){flag = 1;break;}
        curr+=x;
    }

    cout<<even + flag<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}