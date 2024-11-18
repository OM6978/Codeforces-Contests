#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,d,l;
    cin>>n>>d>>l;

    int N = n;

    if(n==l || l==1)
    {
        cout << -1 << '\n';
        return;
    }

    vector<vector<int>> tree(n+1,vector<int>());

    queue<int> last;
    for(int i=0;i<l;i++)last.push(1);

    n--;
    int lvl = 0,curr = 2;
    while(n>0)
    {
        for(int i=0;i<l && n > 0;i++,n--)
        {
            int top = last.front();

            tree[top].push_back(curr++);
            last.pop();
            last.push(curr);
        }
        lvl++;
    }

    int most = 2*lvl;
    if((N-1) % l == 1)
    {
        most--;
    }

    if(most != d)
    {
        cout << -1 << '\n';
        return;
    }

    for(int i=1;i<=N;i++)
    {
        for(int v : tree[i])
        {
            cout << i << ' ' << v << '\n';
        }
    }
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
    //     freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}