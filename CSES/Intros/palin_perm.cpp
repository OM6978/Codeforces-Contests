#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;

    int freqz[26] = {0};

    for(int x : s)
    {
        int in = x - 'A';
        freqz[in]++;
    }

    int N = s.size();
    int odd = (N&1);
    int oletter = -1;

    for(int i=0;i<26;i++)
    {
        if(freqz[i]&1)
        {
            if(odd == 1)
            {
                odd = 0;
                oletter = i;
                continue;
            }

            cout << "NO SOLUTION\n";
            return;
        }
    }

    for(int i=0;i<26;i++)
    {
        for(int j=0;j<freqz[i]/2;j++)
        {
            cout << (char)(i + 'A');
        }
    }

    if(oletter!=-1)
        cout << (char)(oletter + 'A');

    for(int i=25;i>=0;i--)
    {
        for(int j=0;j<freqz[i]/2;j++)
        {
            cout << (char)(i + 'A');
        }
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();
    
    return 0;
}