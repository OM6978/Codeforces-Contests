#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    
    int Test;
    scanf("%d",&Test);
    for(int lol=0;lol<Test;lol++)
    {
    int n,k;
    cin>>n>>k;
    string words;
    cin>>words;

    if(k%2==0)
    {
        sort(words.begin(),words.end());
        cout<<words<<"\n";
        continue;
    }

    string words2,words3;

    for(int i=0;i<words.size();i++)
    {
        if(i%2==0)
        {
            words2.push_back(words[i]);
        }
        else
        {
            words3.push_back(words[i]);
        }
    }
    sort(words2.begin(),words2.end());
    sort(words3.begin(),words3.end());

    for(int i=0;i<n;i++)
    {
        if(i%2==0)cout<<words2[i/2];
        else cout<<words3[i/2];
    }
    cout<<"\n";
    }
    return 0;
}