#include <bits/stdc++.h>
using namespace std;

void makescore(int a,int b,int & score)
{
    if(a>b)score++;
    else if(a<b)score--;
}

int get_num(int a1,int a2,int b1,int b2)
{
    int score = 0;
    makescore(a1,b1,score);
    makescore(a2,b2,score);
    return 2*(score>0);
}

void solve()
{
    int a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;

    cout << get_num(a1,a2,b1,b2) + get_num(a1,a2,b2,b1) << '\n';
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