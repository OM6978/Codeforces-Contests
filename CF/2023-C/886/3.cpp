#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int pair<int>

void solve()
{
    char input[8][8];
    int column=-1,row=-1;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin>>input[i][j];
            if(input[i][j]!='.'&&column==-1){column=j;row=i;}
        }
    }
    for(int k=row;input[k][column]!='.'&&k<=7;k++)cout<<input[k][column];
    cout<<endl;
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