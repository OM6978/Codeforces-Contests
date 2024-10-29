#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '
#define int long long

int m1,m2;
bool getthing(int a[][3],int N,int tot,vector<int>& order)
{
    m1=-1,m2=-1;
    int m3 = -1;

    int currsum = 0;
    for(int i=0;i<N;i++)
    {
        currsum+= a[i][order[0]-1];
        if(currsum >= ceil((double)tot/3))
        {
            m1 = i;
            break;
        }
    }
    if(m1 == -1)return false;

    currsum = 0;
    for(int i=m1+1;i<N;i++)
    {
        currsum+= a[i][order[1]-1];
        if(currsum >= ceil((double)tot/3))
        {
            m2 = i;
            break;
        }
    }
    if(m2 == -1)return false;

    currsum = 0;
    for(int i=m2+1;i<N;i++)
    {
        currsum+= a[i][order[2]-1];
        if(currsum >= ceil((double)tot/3))
        {
            m3 = i;
            break;
        }
    }
    if(m3 == -1)return false;

    return true;
}

void solve()
{
    int N;
    cin>>N;

    int a[N][3];
    for(int i=0;i<N;i++)cin>>a[i][0];
    for(int i=0;i<N;i++)cin>>a[i][1];
    for(int i=0;i<N;i++)cin>>a[i][2];

    int tot = 0;
    for(int i=0;i<N;i++)tot+=a[i][0];

    vector<vector<int>> vect 
    { 
        {1, 2 ,3},  
        {1, 3, 2},  
        {2, 1, 3},
        {2, 3, 1},  
        {3, 1, 2},  
        {3, 2, 1},  
    }; 

    int l[3][2];
    for(int i=0;i<6;i++)
    {
        if(getthing(a,N,tot,vect[i]))
        {
            l[vect[i][0]-1][0] = 1;
            l[vect[i][0]-1][1] = m1+1;
            l[vect[i][1]-1][0] = m1+2;
            l[vect[i][1]-1][1] = m2+1;
            l[vect[i][2]-1][0] = m2+2;
            l[vect[i][2]-1][1] = N;

            // cout<<i<<sp<<m1<<sp<<m2<<endl;
            for(int k=0;k<3;k++)
            {
                for(int j=0;j<2;j++)
                {
                    cout<<l[k][j]<<sp;
                }
            }
            cout<<endl;

            return;
        }
    }

    cout<<-1<<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}