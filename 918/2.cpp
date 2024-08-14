#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    char square[3][3];
    int flag=-1,check=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>square[i][j];
            if(square[i][j]=='?')
            {
                flag = 1;
            }
            else check+=(int)square[i][j]-65;
        }
        if(flag!=-1)
        {
            if(check==1)cout<<'C'<<endl;
            else if(check==2)cout<<'B'<<endl;
            else cout<<'A'<<endl;
        }
        check=0;
        flag=-1;
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