#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

char introchar(int a)
{
    if(a==0)return 'C';
    else if(a==1)return 'D';
    else if(a==2)return 'H';
    else return 'S';
}

void solve()
{
    int N;
    cin>>N;
    char ace;
    cin>>ace;

    int conf =0;
    int files[4] ={0};
    vector<vector<int>> filessss;
    v_int Cfile,Dfile,Hfile,Sfile;

    string s;
    for(int i=0;i<2*N;i++)
    {
        cin>>s;

        if(s[1]=='C'){files[0]++;Cfile.push_back(((int)s[0]) - 48);}
        else if(s[1]=='D'){files[1]++;Dfile.push_back(((int)s[0]) - 48);}
        else if(s[1]=='H'){files[2]++;Hfile.push_back(((int)s[0]) - 48);}
        else {files[3]++;Sfile.push_back(((int)s[0]) - 48);}
    }

    sort(Cfile.begin(),Cfile.end());
    sort(Dfile.begin(),Dfile.end());
    sort(Hfile.begin(),Hfile.end());
    sort(Sfile.begin(),Sfile.end());

    filessss.push_back(Cfile);
    filessss.push_back(Dfile);
    filessss.push_back(Hfile);
    filessss.push_back(Sfile);

    int non =0;
    if(ace == 'C')non=0;
    else if(ace == 'D')non=1;
    else if(ace == 'H')non=2;
    else non=3;

    for(int i=0;i<4;i++)
    {
        if(i!=non)
        {
            files[i]=files[i]%2;
            conf+=files[i];
        }
    }

    files[non]-=conf;
    if(files[non]<0)cout<<"IMPOSSIBLE"<<endl;
    else if(files[non]%2==1)cout<<"IMPOSSIBLE"<<endl;
    else
    {
        int count=0;
        for(int j=0;j<4;j++)
        {
            if(j!=non)
            {
                for(int i=1;i<filessss[j].size();i+=2)
                {
                    cout<<filessss[j][i-1]<<introchar(j)<<space;
                    cout<<filessss[j][i]<<introchar(j)<<endl;
                }
                if(filessss[j].size()%2==1)
                {
                    cout<<filessss[j][filessss[j].size()-1]<<introchar(j)<<space;
                    cout<<filessss[non][count++]<<introchar(non)<<endl;
                }
            }
        }

        for(int i=count;i<filessss[non].size();i+=2)
        {
            cout<<filessss[non][i]<<introchar(non)<<space;
            cout<<filessss[non][i+1]<<introchar(non)<<endl;
        }
    }
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