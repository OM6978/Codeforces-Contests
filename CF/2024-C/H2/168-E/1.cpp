#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;

    int N = s.size();
    int prev = -1,flag = 0;

    for(int i=0;i<N;i++)
    {
        if(s[i] == prev)
        {
            if(prev != (int)'z')
                s.insert(s.begin() + i,prev + 1);
            else s.insert(s.begin()+i,'a');

            flag = 1;

            break;
        }
        prev = s[i];
    }

    if(flag == 0)
    {
        if(prev != (int)'z')
            s.push_back(prev + 1);
        else s.push_back('a');
    }

    cout<<s<<'\n';
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