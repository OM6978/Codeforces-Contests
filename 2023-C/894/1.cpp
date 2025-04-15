#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Test;
    scanf("%d",&Test);
    for(int i=0;i<Test;i++)
    {
    int M,N;
    cin>>M>>N;
    char carpet[M][N+1];
    char temp;
    scanf("%c",&temp);
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N+1;j++)
        {
            scanf("%c",&carpet[i][j]);
        }
    }

    char name[5]="vika";
    int l=0,ans=1;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(carpet[j][i]==name[l])
            {
                l++;
                if(l==4)
                {
                    ans=0;
                }
                break;
            }
        }
        if(ans==0)break;
    }

    if(ans==0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    }
    return 0;
}