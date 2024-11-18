#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

bool isbeut(string & s,int i)
{
    return (s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0');
}

void solve()
{
    string s;
    cin>>s;

    unordered_map<int,int,custom_hash> poss;
    int beut = 0;
    for(int i=0;i<s.size()-3;i++)
    {
        if(isbeut(s,i))
        {
            poss[i]=1;
            beut++;
        }
    }

    int Q;
    cin>>Q;

    while(Q--)
    {
        int j,val;
        cin>>j>>val;
        j--;

        int x = val + '0';
        s[j] = x;

        for(int i=max(0,j-3);i<=min(j,(int)s.size()-4);i++)
        {
            if(isbeut(s,i))
            {
                if(poss[i]==0)beut++;
                poss[i]=1;
            }
            else
            {
                if(poss[i]==1)beut--;
                poss[i] = 0;
            }
        }

        if(beut)cout << "YES\n";
        else cout << "NO\n";
    }
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