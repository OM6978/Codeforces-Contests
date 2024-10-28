#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

v_int factors;

void findfactors(int N)
{
    int sqroot = (int)sqrt(N);
    for(int i = 1; i <= sqroot; i++)
    {
        if(N % i == 0)
        {
            factors.push_back(i);
            factors.push_back(N/i);
        }
    }
}

void solve()
{
    factors.clear();

    int N;
    cin>>N;
    string s;
    cin>>s;

    findfactors(N);

    for(int i=0;i<factors.size();i++)
    {
        
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