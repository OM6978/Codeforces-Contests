#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int whatisit(char l)
{
    if(l=='b'||l=='d'||l=='c')return 1;
    else return 0;
}
void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int temp=0;
    for(int i=0;i<n;i++)
    {
        temp++;
        if(temp==3)
        {
            temp=0;
            if(whatisit(s[i+1])==0&&i+1!=n){cout<<'.';temp++;}
            else if(i+1!=n)
            {
                cout<<s[i]<<'.';
                continue;
            }
        }
        cout<<s[i];
    }
    cout<<endl;
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