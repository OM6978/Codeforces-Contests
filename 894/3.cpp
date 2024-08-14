#include <iostream>
#include <stdlib.h>
#include <string.h>
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
    int len;
    scanf("%d",&len);
    int fence[len];

    for(int i=0;i<len;i++)
    {
        scanf("%d",&fence[i]);
    }

    int ans=0;
    if(fence[0]>len)
    {
        ans=1;
        printf("NO\n");
        continue;
    }

    int fencehori[len],index=0;

    for(int i=len-1;i>=0;i--)
    {
        for(int j=fence[i]-1;j>=index;j--)
        {
            fencehori[j]=i+1;
        }
        index=fence[i];
    }

    for(int i=0;i<len;i++)
    {
        if(fencehori[i]!=fence[i])
        {
            ans=1;
            break;
        }
    }

    if(ans==0)
    {
        printf("YES\n");
    }
    else printf("NO\n");
    }
    return 0;
}