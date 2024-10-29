#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

void solve()
{
    int x,y,k;
    cin>>x>>y>>k;

    if(x%y==0)
    {
        x++;
        k--;
    }
    if(y==1)
    {
        x+=k;
        k=0;
    }

    while(k)
    {
        int diff = (y - x%y)%y;

        if(diff > k)
        {
            x+=k;
            k=0;
        }
        else
        {
            k-=diff;
            x+=diff;

            while(x%y==0)x/=y;

            if(x < y)break;
        }
    }

    if(k==0)cout<<x<<endl;
    else
    {
        int diff = (y - x%y)%y;
        if(diff > k)
        {
            x+=k;
            k=0;
        }
        else
        {
            k-=diff;
            x=1;

            k%=(y-1);
            x=(x+k);
        }

        cout<<x<<endl;
    }
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