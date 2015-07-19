/*************************************************************************
    > File Name: 蛇形矩阵.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com
    > Created Time: 2015年06月11日 星期四 21时59分20秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void){
	int n;
	int d;
	int temp;
	int sum;
	int i, j, t, m, l;
	int a[101][101];
	scanf("%d", &temp);
	n =temp;
	d = n * n;
	for(i = n - 1; i >= 0; i --){
		for(j = i; j >= temp - n; j --){
			a[i][j] = d;
			d --;
			if(j == temp - n){
				for(m = i - 1; m >=temp - n; m --){
					a[m][j] = d;
					d--;
					if(m == temp - n){
						for(t = j + 1; t <= n - 1; t ++){
							a[m][t] = d;
							d --;
							if(t == n -1){
								for(l = m + 1; l <= i - 1; l ++){
									a[l][t] = d;
									d --;
								}
							}
						}
					}
				}
			}
		}
		n --;
	}
	for(i = 0; i < temp; i ++, printf("\n"))
		for(j = 0; j < temp; j ++){
            if(i == j || i + j  == temp -1 )
            sum += a[i][j];
			printf("%d\t ", a[i][j]);
			}
			printf("%d", sum);
}

