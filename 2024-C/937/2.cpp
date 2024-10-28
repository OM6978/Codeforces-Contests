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

    char arr[2*N][2*N];
    int flag=0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(flag==0)
            {
                arr[2*i][2*j] =  '#';
                arr[2*i][2*j + 1] =  '#';
                arr[2*i + 1][2*j + 1] =  '#';
                arr[2*i + 1][2*j] =  '#';
                if(!(N%2==0 && j==N-1))flag=1;
            }
            else
            {
                arr[2*i][2*j] =  '.';
                arr[2*i][2*j + 1] =  '.';
                arr[2*i + 1][2*j + 1] =  '.';
                arr[2*i + 1][2*j] =  '.';
                if(!(N%2==0 && j==N-1))flag=0;
            }
        }
    }

    for(int i=0;i<2*N;i++)
    {
        for(int j=0;j<2*N;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
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