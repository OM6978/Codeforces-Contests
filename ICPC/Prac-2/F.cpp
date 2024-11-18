#include <bits/stdc++.h>
using namespace std;

// int makemake(int * freqz,vector<int> & tomake,vector<vector<int>> & stats)
// {

// }

vector<int> get_stats(int x,int* ar,int N)
{
    vector<int> ret(3,0);

    for(int i=0;i<N;i++)
    {
        if(ar[i] == x)ret[i%3]++;
    }

    return ret;
}

int makearr(int* freqz,int* ar,int N)
{
    vector<vector<int>> stats;
    auto another = stats;

    stats.push_back(get_stats(freqz[0],ar,N));
    stats.push_back(get_stats(freqz[1],ar,N));
    stats.push_back(get_stats(freqz[2],ar,N));

    vector<int> tomake(3,-1);
    for(int i=0;i<3;i++)
    {
        int maxin = max_element(stats[i].begin(),stats[i].end()) - stats[i].begin();
        tomake[i] = stats[i][maxin];

        for(int j=i+1;j<3;j++)
        {
            stats[j][maxin] = 0;
        }
    }

    for(int i=0;i<3;i++)
    cout << tomake[i] << ' ';

    cout << '\n';

    return 0;
}

void solve()
{
    int N;
    cin>>N;

    int freqz[201] = {0};

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        freqz[ar[i]]++;
    }

    sort(freqz,freqz+201,greater<int>());

    cout << makearr(freqz,ar,N) << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}