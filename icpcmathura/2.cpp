#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n;
char* str1,*str2;
int check(int l2,int r2,int i)
{
    int stat=0;
    for(i=i;i>=0;i--)
    {
        if((str2[l2]==str2[r2])&&(str2[l2]==str1[i]))
        {
            stat+=check(l2+1,r2,i-1);
            if(stat==0){break;}
            stat+=check(l2,r2-1,i-1);
            if(stat==2)
            {
                stat=1;
                break;
            }
            else
            {
                stat=0;
                break;
            }
        }
        else if(str1[i]==str2[r2])
        {
            r2--;
            continue;
        }
        else if(str1[i]==str2[l2])
        {
            l2++;
        }
        else
        {
            stat=1;
            break;
        }
    }
    return stat;
}
int main()
{
    int Test;
    scanf("%d",&Test);
    int res[Test];
    for(int i=0;i<Test;i++)
    {
    scanf("%d",&n);
    char s1[n],s2[n];
    str1=&s1[0];
    str2=&s2[0];
    int l2=0,r2=n-1,stat=0;
    scanf("%s",s1);
    scanf("%s",s2);
    for(int i=n-1;i>=0;i--)
    {
        if((str2[l2]==str2[r2])&&(str2[l2]==str1[i]))
        {
            stat+=check(l2+1,r2,i-1);
            if(stat==0){break;}
            stat+=check(l2,r2-1,i-1);
            if(stat==2)
            {
                stat=1;
                break;
            }
            else
            {
                stat=0;
                break;
            }
        }
        if(str1[i]==str2[r2])
        {
            r2--;
            continue;
        }
        else if(str1[i]==str2[l2])
        {
            l2++;
        }
        else
        {
            stat=1;
            break;
        }
    }
    res[i]=stat;
    }
    for(int i=0;i<Test;i++)
    {
        if(res[i]==0)
        {
            printf("Case %d: YES\n",i+1);
        }
        else
        {
            printf("Case %d: NO\n",i+1);
        }
    }
    return 0;
}