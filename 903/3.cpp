#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int findopers(int *a)
{
    int max=0;
    for(int i=1;i<4;i++)
    {
        if(a[i]>a[max])max=i;
    }

    int opers=0;
    for(int i=0;i<4;i++)
    {
        if(i==max)continue;
        else
        {
            opers+=a[max]-a[i];
        }
    }

    return opers;
}

void solve()
{
    int N;
    cin>>N;

    char mat[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>mat[i][j];
        }
    }

    int opers=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int temp[] = {mat[i][j],mat[j][N-i-1],mat[N-i-1][N-j-1],mat[N-j-1][i]};
            opers+=findopers(temp);
        }
    }

    cout<<opers/4<<endl;
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