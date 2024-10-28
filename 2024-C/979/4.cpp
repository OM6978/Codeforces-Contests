#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,Q;
    cin>>N>>Q;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    string s;
    cin>>s;

    set<int> potent;

    int most = 0;
    for(int i=0;i<N;i++)
    {
        most = max(ar[i],most);
        if(most==i+1)potent.insert(i+1);
    }

    set<int> given;
    
    int useless=0;
    for(int i=0;i<N-1;i++)
    {
        if(s[i] == 'L' && s[i+1] == 'R')
        {
            if(potent.find(i+1)==potent.end())useless++;
            given.insert(i+1);
        }
    }

    while(Q--)
    {
        int arg;
        cin>>arg;

        if(s[arg-1] == 'L')
        {
            s[arg-1] = 'R';
            if(arg!=1 && s[arg-2] == 'L')
            {
                int lol = arg-1;
                given.insert(lol);
                if(potent.find(lol) == potent.end())useless++;
            }
            if(arg!=N && s[arg] == 'R')
            {
                given.erase(arg);
                if(potent.find(arg) == potent.end())useless--;
            }
        }
        else
        {
            s[arg-1] = 'L';
            if(arg!=1 && s[arg-2] == 'L')
            {
                int lol = arg-1;
                given.erase(lol);
                if(potent.find(lol) == potent.end())useless--;
            }
            if(arg!=N && s[arg] == 'R')
            {
                given.insert(arg);
                if(potent.find(arg) == potent.end())useless++;
            }
        }

        cout << ((useless==0)?"YES\n":"NO\n");
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}