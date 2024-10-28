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

    int vert=0,hori=0;
    for(int i=0;i<N;i++)
    {
        if(s[i] == 'N')vert++;
        else if(s[i] == 'S')vert--;
        else if(s[i] == 'E')hori++;
        else if(s[i] == 'W')hori--;
    }

    if((vert&1)||(hori&1))
    {
        cout<<"NO"<<endl;
        return;
    }
    else if(vert == 0 && hori == 0)
    {
        int l=0;
        if(N>=4)
        {
            cout<<'H';
            if(s[0] == 'N')l=1;
            else if(s[0] == 'S')l=2;
            else if(s[0] == 'E')l=3;
            else if(s[0] == 'W')l=4;

            for(int i=1;i<N;i++)
            {
                if(s[i] == 'N' && l==2){cout<<'H';l=0;}
                else if(s[i] == 'S' && l==1){cout<<'H';l=0;}
                else if(s[i] == 'E' && l==4){cout<<'H';l=0;}
                else if(s[i] == 'W' && l==3){cout<<'H';l=0;}
                else
                {
                    cout<<'R';
                }
            }
            cout<<endl;
            return;
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    int firvert=0,firhori=0,flag=0,flag2=0;
    for(int i=0;i<N;i++)
    {
        if(firvert == vert/2)flag=1;
        if(firhori == hori/2)flag2=1;

        if(flag==0 && (s[i] == 'N'||s[i] == 'S'))
        {
            if(s[i] == 'N')firvert++;
            else if(s[i] == 'S')firvert--;

            cout<<'H';
            continue;
        }
        if(flag2 ==0 && ((s[i] == 'E'||s[i] == 'W')))
        {
            if(s[i] == 'E')firhori++;
            else if(s[i] == 'W')firhori--;

            cout<<'H';
            continue;
        }
        cout<<'R';
    }
    cout<<endl;
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