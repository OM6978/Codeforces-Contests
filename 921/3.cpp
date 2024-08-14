#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

unordered_map<int,int> m1;

void solve()
{
    int n,k,m;
    cin>>n>>k>>m;
    string s;
    cin >> s;

    char leader = s[0];
    int num =0, numlead = 1,leaves = n-k , hauls =0;
    for(int i=1;i<m;i++)
    {
        if(s[i]!=leader)
        {
            m1[(char)((int)s[i]-97)]++;
            if(m1[(char)((int)s[i]-97)]>1)
            {
                leaves++;
                if(leaves>1)
                {
                    cout<< "NO" << endl;m1.clear();return;
                }
            }
            else num++;
        }
        else if(num == k-1)
        {
            hauls++;
            numlead++;
        }
        else {cout<< "NO" << endl;m1.clear();return;}
    }

    if(numlead == n)
    {
        if(num==k-1)cout<< "YES" << endl;
        else cout<< "NO" <<endl;
    }
    else cout << "NO" <<endl;
    
    m1.clear();
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