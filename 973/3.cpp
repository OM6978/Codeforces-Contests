#include <bits/stdc++.h>
using namespace std;

void ask(string & s,char what,bool forwd)
{
    string lol;
    lol.push_back(what);

    if(forwd)cout<< "? " << s + lol << '\n';
    if(!forwd)cout<< "? " << lol + s << '\n';
}

void solve()
{
    int N;
    cin>>N;

    string ans;
    bool forwd = true;

    int resp;
    while(ans.size()!=N)
    {
        ask(ans,'0',forwd);
        cin>>resp;

        if(resp)
        {
            if(forwd)ans.push_back('0');
            else ans.insert(ans.begin(),'0');
            continue;
        }

        if(!forwd && ans.size() == N-1)
        {
            ans.insert(ans.begin(),'1');
            break;
        }

        ask(ans,'1',forwd);
        cin>>resp;

        if(resp)
        {
            if(forwd)ans.push_back('1');
            else ans.insert(ans.begin(),'1');
            continue;
        }
        else forwd = false;
    }

    cout << "! " << ans << '\n';
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
    //     freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    // #endif

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}