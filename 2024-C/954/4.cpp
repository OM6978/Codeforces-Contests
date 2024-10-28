#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

void solve()
{
    int N;
    cin>>N;

    string s;
    cin>>s;

    if(N>3)
    {
        int smol = 0;
        for(int i=1;i<N-1;i++)
        {
            if(s[i]<s[smol])smol = i;
            else if(s[i] == s[smol])
            {
                if((s[i+1] < s[smol+1] && s[i+1] != '1') || s[smol+1] == '1')smol = i;
            }
        }

        if(s[smol] == '0' || s[N-1] == '0')cout<<0<<endl;
        else
        {
            int ans=0;
            for(int i=0;i<N;i++)
            {
                if(i==smol)
                {
                    ans+= stoi(s.substr(i++,2));
                }
                else if(s[i] != '1')ans+= s[i]-'0';
            }

            cout<<ans<<endl;
        }
    }
    else if(N==2)cout<<stoi(s)<<endl;
    else
    {
        int ans = (1<<30),temp;

        temp = stoi(s.substr(0,2)) + s[2] - '0';
        ans = min(ans,temp);

        temp = stoi(s.substr(0,2))*(s[2] - '0');
        ans = min(ans,temp);

        temp = stoi(s.substr(1,2)) + s[0] - '0';
        ans = min(ans,temp);

        temp = stoi(s.substr(1,2))*(s[0] - '0');
        ans = min(ans,temp);

        cout<<ans<<endl;
    }
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