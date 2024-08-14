#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    string s[2];
    cin>>s[0];
    cin>>s[1];

    int regions = 1;
    for(int i=0;i<N;i++)
    {
        if(s[0][i] == 'x')
        {
            if(i!=0 && s[1][i-1] == 'x' && s[0][i-1]!= 'x')
            {
                regions++;
            }
            if(i!=0 && s[1][i] == 'x' && s[1][i-1]!='x' && s[0][i-1] != 'x')
            {
                regions++;
            }
            if(i!=N-1 && s[1][i+1] == 'x' && s[1][i] != 'x')
            {
                regions++;
            }
        }
    }
    if(s[0][N-1] == 'x' && s[1][N-1] == 'x')regions--;

    cout<<regions<<'\n';

    if(regions > 4)cout<< 0 <<'\n';
    else if(regions == 0)cout<< 0 <<'\n';

    int ones = 0,twos = 0,negs = 0;
    for(int i=0;i<N;i++)
    {
        if(s[0][i] == '.')
        {
            if(i!=0 && i!= N-1 && s[1][i-1] == 'x' && s[1][i+1] == 'x' && s[1][i] == '.' && s[0][i-1] == '.' && s[0][i+1] == '.')twos++;
            else if(i!=0 && i!= N-1 && s[1][i] == 'x' && s[0][i-1] == '.' && s[0][i+1] == '.')ones++;
            else if(i!= N-1 && s[1][i+1] == 'x')
            {
                
            }
            else if()
        }
    }

    if(regions == 1)cout << ones <<'\n';
    else if(regions == 2)cout << twos <<'\n';
    else cout<< negs <<'\n';
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