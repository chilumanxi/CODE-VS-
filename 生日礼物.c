/*************************************************************************
    > File Name: 生日礼物.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年06月10日 星期三 16时13分22秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int a[9][11];
int nn[9], mm[11];
int n, m;
int max = 1001;

void solve(int pos){
	int i, j;
	int flag;
	for(i = 0; i <= nn[pos]; i ++){
		for(j = 1; j <= m; j ++)
			mm[j] = mm[j] + a[pos][j] * i;
		if(pos < n)
			solve(pos + 1);
		else{
			for(j = 2; j <= m; j ++){
				if(mm[j] == mm[j - 1])
					flag = 1;
				else{
					flag = 0;
					break;
				}
			}
			if(flag && mm[1] * m < max && mm[1] != 0)
				max = mm[1] * m;
		}
		for(j = 1; j <= m; j++)
			mm[j] = mm[j] - a[pos][j] * i;
	}
}

int main(void){
	int i, j;
	memset(mm, 0, sizeof(mm));
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i ++, getchar())
		for(j = 1; j <= m; j ++)
			scanf("%d", &a[i][j]);
	for(i = 1; i <= n; i ++)
		scanf("%d", &nn[i]);
	solve(1);
	if(max <= 1000)
		printf("%d\n", max);
	else printf("alternative!\n");
	return 0;
			
}
