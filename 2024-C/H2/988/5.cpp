#include <bits/stdc++.h>
using namespace std;

void ask(int x,int y,int & ans){cout << "? " << x << ' ' << y << '\n';cin>>ans;}

void imp(){cout << "! IMPOSSIBLE\n";}

bool findsubstr(int & i,int N,string & s)
{
    int beg = i++,ans=0;
    while(i<=N && ans==0)ask(beg,i++,ans);

    if(ans==0)return false;

    int zeros = ans;
    int ones = i - beg - zeros;

    while(--ones)s.push_back('1');
    while(zeros--)s.push_back('0');
    s.push_back('1');

    return true;
}

void solve()
{
    int N;
    cin>>N;

    string s;

    int i=1,ans;
    while(i<=N)
    {
        if(!findsubstr(i,N,s))
        {
            if(s.size())
            {
                ask(s.size()-1,N,ans);

                int ones = ans - 1,zeros = (N - s.size()) - ones;
                while(ones--)s.push_back('1');
                while(zeros--)s.push_back('0');
            }
            else {imp();return;}
        }
    }

    cout << "! " << s << '\n';
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
    //     freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    // #endif

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}