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
    int len,alen;
    scanf("%d",&len);
    alen=0;

    int b[len],a[len*2];
    scanf("%d",&b[0]);
    a[alen++]=b[0];

    for(int i=1;i<len;i++)
    {
        scanf("%d",&b[i]);

        if(b[i]<b[i-1])
        {
            a[alen++]=b[i];
        }
        a[alen++]=b[i];
    }

    printf("%d\n",alen);
    for(int i=0;i<alen;i++)printf("%d ",a[i]);
    printf("\n");
    }
    return 0;
}