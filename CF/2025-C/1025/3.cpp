#include <bits/stdc++.h>
using namespace std;

#define int long long

void ask(string s,int & x)
{
    cout << s << '\n';
    cin>> x;
}

void solve()
{
    int N;
    cin>>N;

    int x;
    ask("digit",x);

    ask("digit",x);

    ask("add -8",x);

    ask("add -4",x);

    ask("add -2",x);

    ask("add -1",x);

    cout << "add " << N - 1 << '\n';
    cin>>x;
    
    cout << "!\n";
    cin>>x;
}

signed main()
{   
    fflush(stdout) or cout.flush();

    int Testcases;
    cin>>Testcases;
    while(Testcases--)
    {
        solve();
    }
    
    return 0;
}