#include <bits/stdc++.h>
using namespace std;

void ask(int x,int y){cout << "? " << x << ' ' << y << '\n';}

void imp(){cout << "! IMPOSSIBLE";}

void solve()
{
    int N;
    cin>>N;

    string s,last;

    ask(1,2);
    int i =1;
    int ans;
    cin>>ans;

    while(ans==0 && ++i<N)
    {
        ask(1,i+1);
        cin>>ans;
    }

    if(ans==0){imp();return;}

    int ones = i+1 - ans;
    int zeros = i+1 - ones;
    while(ones-->1)s.push_back('1');
    while(zeros--)s.push_back('0');
    s.push_back('1');

    last = "01";

    while(i<N-1)
    {
        if(last == "11")
        {
            int bef = i;
            ask(bef,i+++2);

            cin>>ans;
            while(ans==0 && i<N)
            {
                ask(bef,i+++2);
                cin>>ans;
            }

            if(ans==0){imp();return;}

            int zeros = ans;
            int ones = (i - bef - 1) - ans;

            while(ones--)s.push_back('1');
            while(zeros--)s.push_back('0');
            s.push_back('1');
            last = "01";
        }
        else
        {
            ask(i,i+2);
            cin>>ans;

            char pred;
            if(last == "00")
            {
                if(ans == 2)pred = '1';
                else pred = '0';
            }
            else if(last == "10")
            {
                if(ans == 1)pred = '1';
                else pred = '0';
            }
            else
            {
                if(ans == 2)pred = '1';
                else pred = '0';
            }

            s.push_back(pred);
            last.erase(last.begin());
            last.push_back(pred);
            i++;
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