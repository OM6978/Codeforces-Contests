#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A,vector<int> &B)
{
    int N = A.size();
    int pre[N+1];
    pre[0] = -1e9;
    for(int i=0;i<N;i++)pre[i+1] = max(pre[i],A[i]);

    int suf[N+1];
    suf[N] = -1e9;
    for(int i=N-1;i>=0;i--)suf[i] = max(suf[i+1],B[i]);

    int ans = 0;
    for(int i=0;i<N;i++)
    {
        ans = min(ans,max(pre[i+1],suf[i]));
    }

    return ans;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}