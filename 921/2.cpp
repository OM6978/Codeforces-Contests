#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int x,n,i;
    cin>>x>>n;
    int flag=0,lol = ((int)sqrt(x))+1;
    if(n<lol)
    {
        for(i=n;i<lol;i++)
        {
            if(x%i==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<x/i<<endl;
        }
        else
        {
            for(i=n-1;i>=2;i--)
            {
                if(x%i==0 && x/i >=n)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                cout<< i <<endl;
            }
            else cout<<1<<endl;
        }
    }
    else
    {
        for(i=lol-1;i>=2;i--)
        {
            if(x%i==0 && x/i >=n)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)cout<<i<<endl;
        else cout<<1<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}