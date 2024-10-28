#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int pair<int>

int findpoints(int i,int j)
{
    if(min(i,j)==0||max(i,j)==9)return 1;
    else if(min(i,j)==1||max(i,j)==8)return 2;
    else if(min(i,j)==2||max(i,j)==7)return 3;
    else if(min(i,j)==3||max(i,j)==6)return 4;
    else if(min(i,j)==4||max(i,j)==5)return 5;
}

void solve()
{
    char grid[10][10];
    int points=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='X')points+=findpoints(i,j);
        }
    }

    cout<<points<<endl;
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