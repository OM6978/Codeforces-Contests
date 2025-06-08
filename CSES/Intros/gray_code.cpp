#include <bits/stdc++.h>
using namespace std;

void printstate(vector<int> & state)
{
    for(int x : state)
    {
        cout << x;
    }
    cout << '\n';
}

void printperms(int i,vector<int> & state)
{
    int N = state.size();
    if(i==N)
    {
        printstate(state);
        return;
    }

    printperms(i+1,state);

    state[i] = 1 - state[i];

    printperms(i+1,state);
}

void solve()
{
    int N;
    cin>>N;

    vector<int> state(N,0);

    printperms(0,state);
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