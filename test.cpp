#include <stdio.h>
#include <string.h>

int n;
int book[11];
int s[11];

void dfs(int num)
{
    int i;
    if(num==1)
    {
        memset(book,0,11*sizeof(int));
        memset(s,0,11*sizeof(int));
    }
    if(num==n+1)
    {
        for(i=1;i<=n;i++)
            printf("%d ",s[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(book[i])
            continue;
        book[i]=1;
        s[num]=i;
        dfs(num+1);
        book[i]=0;
    }
    return;
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}
