#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    vector<map<int,int>> vmp(11,map<int,int>());
    vector<int> last(11,0);
    int banksum[11][2] = {0};
    vector<int> prez(11,0);
    vector<int> banks(11,0);

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int ans = 0;
    for(int i=0;i<N;i++)
    {
        prez[ar[i]] = 1;

        for(int j=1;j<=10;j++)
        {
            int bank = banks[j];

            if(ar[i] > j)
            {
                banksum[j][bank&1] -= vmp[j][last[j] - bank + 1] - vmp[j][last[j] + bank - 1];

                last[j]++;
            }
            else if(ar[i] < j)
            {
                banksum[j][bank&1]  += vmp[j][last[j] - bank + 1] - vmp[j][last[j] + bank - 1];
                last[j]--;
            }
            else
            {
                bank++;
                banks[j]++;

                if(bank!=1)
                    banksum[j][bank&1] += vmp[j][last[j] + bank - 1] + vmp[j][last[j] - bank + 1];
            }

            if(prez[j])ans += banksum[j][bank&1] + vmp[j][last[j]] + (last[j]==0 && j==ar[i]);

            vmp[j][last[j]]++;
            // banksum[j][bank&1]++;

            cout << i << ' ' << j << ' ' << last[j] << ' ' << banksum[j][bank&1] << ' ' << ans << '\n';
        }
    }

    cout << ans << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}