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
    string s;
    cin>>s;
    int plus=0,minus=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='+')plus++;
        else minus++;
    }
    cout<<abs(plus-minus)<<endl;
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