/*************************************************************************
    > File Name: 选数.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com
    > Created Time: 2015年06月09日 星期二 10时09分32秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int n, k; //n为整数个数,k为任选几个数
int a[21];

int flag[21];
int res = 0;


int check_prim(int n){
	int i;
	if(n == 1 || n == 0)
		return 0;
	for(i = 2; i *i <= n; i ++ ){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

void dfs(int step, int pos, int sum){
	int i;
	memset(flag, 0, sizeof(flag));
	if(step == k && check_prim(sum)){
		res ++;
		return ;
	}
	else if(step == k)
		return ;
	int vv[21];
	for(i = 0; i < n; i ++){
		vv[i] = flag[i];
	}
	for(i = pos + 1; i < n; i ++){
		if(!vv[i])
			dfs(step + 1, i, sum + a[i]);
	}
	for(i = 0; i < n; i ++)
		flag[i] = vv[i];
}



int main(void){
	int i;
	scanf("%d%d", &n, &k);
	for(i = 0; i  < n; i ++){
		scanf("%d", &a[i]);
	}
	dfs(0, -1, 0);
	printf("%d",res);

}

