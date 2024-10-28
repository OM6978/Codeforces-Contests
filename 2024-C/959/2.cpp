#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

void solve()
{
    int N;
    cin>>N;

    string s,t;
    cin>>s>>t;

    int firstdiff = -1,firstone = -1;
    for(int i=0;i<N;i++)
    {
        if(s[i] != t[i] && firstdiff == -1)
            firstdiff = i;

        if(s[i] == '1' && firstone == -1)
            firstone = i;
    }

    if((firstone > firstdiff && firstdiff!=-1) || (firstdiff!=-1 && firstone == -1))
        cout<<"NO"<<endl;
    else cout<< "YES" <<endl;
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