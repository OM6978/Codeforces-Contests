#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '
#define int long long

void solve()
{
    int N,M,K;
    cin>>N>>M>>K;

    int mat[N][M],type[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>mat[i][j];
        }
    }

    int sum[2] = {0};
    int presu[N][M];
    string s;
    for(int i=0;i<N;i++)
    {
        cin>>s;
        for(int j=0;j<M;j++)
        {
            type[i][j] = s[j] - '0';
            sum[type[i][j]]+=mat[i][j];

            if(i!=0 || j!=0)
            {
                if(j!=0)
                    presu[i][j] = presu[i][j-1] + type[i][j] - (type[i][j]==0);
                else
                    presu[i][j] = presu[i-1][M-1] + type[i][j] - (type[i][j]==0);
            }
            else presu[i][i] = type[i][j] - (type[i][j]==0);
        }
    }

    int g_ar = -1;
    for(int i=0;i<=N-K;i++)
    {
        for(int j=0;j<=M-K;j++)
        {
            int topush = 0;
            for(int p=i;p<i+K;p++)
            {
                if(p==0 && j==0)topush+= presu[p][j+K-1];
                else if(j!=0)topush += presu[p][j+K-1] - presu[p][j-1];
                else topush+= presu[p][j+K-1] - presu[p-1][M-1];
            }

            if(topush!=0)
            {
                if(g_ar == -1)
                    g_ar = abs(topush);
                else g_ar = __gcd(g_ar,abs(topush));
            }
        }
    }

    if(sum[0] == sum[1])cout<<"YES"<<endl;
    else if(g_ar == -1)cout<<"NO"<<endl;
    else cout<< ((abs(sum[1] - sum[0])%g_ar != 0)?"NO":"YES") <<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}