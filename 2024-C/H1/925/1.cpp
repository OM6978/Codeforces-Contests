#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;

    if(N<=28)
    {
        int a = N - 2 +96;
        cout<<'a'<<'a'<<(char)a<<endl;
    }
    else if(N<=53)
    {
        int a = N - 1 - 26 +96;
        cout<<'a'<<(char)a<<'z'<<endl;
    }
    else
    {
        int a = N - 2*26 + 96;
        cout<<(char)a<<'z'<<'z'<<endl;
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