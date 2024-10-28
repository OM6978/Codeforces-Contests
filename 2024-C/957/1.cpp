#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

int getmin(int* a)
{
    int min = 0;
    for(int i=0;i<3;i++)
    {
        if(a[i]<a[min])min = i;
    }

    return min;
}

void solve()
{
    int a[3];
    for(int i=0;i<3;i++)cin>>a[i];

    for(int i=0;i<5;i++)
    {
        int in = getmin(a);
        a[in]++;
    }

    cout <<a[0]*a[1]*a[2]<<endl;
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