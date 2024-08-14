#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

int getnextlog(string& s,int i)
{
    while(s[++i] != 'L');
    return i;
}

void solve()
{
    int n,M,K;
    cin>>n>>M>>K;

    string s;
    cin>>s;

    s.push_back('L');
    s.insert(s.begin(),'L');
    int N = s.size();

    int i=0;
    while(i!=N-1)
    {
        int next = getnextlog(s,i);

        if(next - i <= M)i = next;
        else
        {
            i+=M;
            while(i!=next)
            {
                if(s[i] == 'C' || K==0)
                {
                    cout<<"NO"<<endl;
                    return;
                }
                i++,K--;
            }
        }
    }

    cout<<"YES"<<endl;
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