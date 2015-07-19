/*************************************************************************
    > File Name: 电话连线.c
    > Author: zhanghaoran
    > Mail: 467908670@qq.com 
    > Created Time: 2015年05月25日 星期一 10时03分14秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define INF 100000
int Prim(int a[][100], int n){
	int low[100];
	int b[100][2];
	int used[100];
	int closeset[100];
	int i, j, k, min;
	int flag = 0;
	int icount = 0;
	int count = 0;
	int t = 0;
	for(i = 0; i < n ; i ++){
		low[i] = a[0][i];
		used[i] = 0;
		closeset[i] = 0;
	}
	used[i] = 0;
	for(i = 0; i < n - 1; i++){
		j = 0;
		min = INF;
		for(k = 1; k < n; k ++)
			if(!used[k] && low[k] < min){
 	 			j = k;
				min = low[k];
				if(min == 0){
	   				flag = 1;
					break;
				}
			}
		used[j] = 1;
		count += min;
		if(flag == 0){
			icount ++;
			b[t][0] = j + 1 < closeset[j] + 1 ? j + 1 : closeset[j] + 1;
			b[t][1] = j + 1 > closeset[j] + 1 ? j + 1 : closeset[j] + 1;
			t ++;
		}
		flag = 0;
		for(k = 1; k < n; k ++)
			if(!used[k] && a[j][k] < low[k]){
	  			low[k] = a[j][k];
	 			closeset[k] = j;
		}
	}
	printf("%d\n", icount);
	for(i = 0; i < icount; i++){
		printf("%d %d\n", b[i][0], b[i][1]);
	}
	return count;
}

int main(void){
	int n;
	int a[100][100];
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i ++){
		for(j = 0; j < n; j ++){
			scanf("%d", &a[i][j]);
		}
	} 
	printf("%d\n", Prim(a, n));
}
