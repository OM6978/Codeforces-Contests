#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;

    char temp;

    string s;
    cin>>s;
    
    int x=0,y=0;
    for(int i=0;i<N;i++)
    {
        temp=s[i];
        if(temp=='U')y++;
        else if(temp=='R')x++;
        else if(temp=='L')x--;
        else y--;

        if(x==1 && y==1){cout<<"YES"<<endl;return;}
    }

    cout<<"NO"<<endl;
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