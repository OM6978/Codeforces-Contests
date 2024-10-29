#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int sec = ar[N-1],lastart = 0;
    int temp;

    for(int i=N-2;i>=0;i--)
    {
        if(ar[i] > ar[i+1] && ar[i] - lastart > ar[i+1])
        {
            temp = ar[i];
            lastart = 0;
        }
        else
        {
            temp = lastart + ar[i+1] + 1;
            lastart = lastart + ar[i+1] - ar[i] +1;
        }

        sec = max(temp,sec);
    }

    cout<<sec<<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}