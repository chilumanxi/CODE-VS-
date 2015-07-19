/*************************************************************************
    > File Name: 二叉树最大宽度和高度.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年06月12日 星期五 15时04分33秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int tree[20];
int a[20][2];
int max = 0, pos = 0;

int solve(int step, int pos){
	tree[step] = tree[step] + 1;
	if(step > max)
		max = step;
	if(a[pos][0] != 0)
		solve(step + 1, a[pos][0]);
	if(a[pos][1] != 0)
		solve(step + 1, a[pos][1]);
}



int main(void){
	int n;
	int i;
	scanf("%d", &n);
	memset(tree, 0, sizeof(tree));
	memset(a, 0, sizeof(a));
	for(i = 1; i <= n; i ++){
		scanf("%d%d", &a[i][0], &a[i][1]);
	}
	solve(1,1);
	for(i = 1; i <= n; i ++){
		if(tree[i] > pos)
			pos = tree[i];
	}
	printf("%d %d\n", pos, max); 
}
