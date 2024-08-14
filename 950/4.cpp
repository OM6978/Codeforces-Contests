#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

bool check(vector<int>&g_ar)
{
    for(int i=1;i<g_ar.size();i++)
    {
        if(g_ar[i-1]>g_ar[i])return false;
    }
    return true;
}

bool remove(int i,vector<int>&g_ar,int* ar,int N)
{
    if(i==0)
    {
        vector<int> temp = (vector<int>){g_ar.begin()+1,g_ar.end()};
        return check(temp);
    }

    int temp1 = g_ar[i-1],temp2 = g_ar[i];
    g_ar.erase(g_ar.begin()+i);
    g_ar[i-1] = __gcd(ar[i-1],ar[i+1]);

    if(!check(g_ar))
    {
        g_ar[i-1] = temp1;
        g_ar.insert(g_ar.begin() + i,temp2);

        return false;
    }
    else return true;
}

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    vector<int> g_ar(N-1);
    cin>>ar[0];

    for(int i=1;i<N;i++)
    {
        cin>>ar[i];
        g_ar[i-1] = __gcd(ar[i-1],ar[i]);
    }

    for(int i=1;i<N-1;i++)
    {
        if(g_ar[i] < g_ar[i-1])
        {
            if(remove(i-1,g_ar,ar,N)){cout<<"YES"<<endl;return;}
            else if(remove(i,g_ar,ar,N)){cout<<"YES"<<endl;return;}
            else if(remove(i+1,g_ar,ar,N)){cout<<"YES"<<endl;return;}
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;
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