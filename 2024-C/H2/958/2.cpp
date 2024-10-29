#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

void solve()
{
    int N;
    cin>>N;

    string s,new_s;
    cin>>s;

    int zeros=0,ones=0;
    int i=0;
    while(i!=N)
    {
        new_s.push_back(s[i]);
        if(s[i] == '0')
        {
            while(i!=N && s[i] == '0')i++;
            zeros++;
        }
        else i++,ones++;
    }

    cout<<((ones>zeros)?"YES":"NO")<<endl;
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