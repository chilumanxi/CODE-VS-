/*************************************************************************
    > File Name: Cantor表.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年06月11日 星期四 20时33分05秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main(void){
	int N;
	int i;
	int res = 0;
	scanf("%d", &N);
	for(i = 1; N - i > 0; i ++){
		res ++;
		N = N - i;
	}
	if(res % 2 == 1){
		printf("%d/%d", N,  res + 2 - N);
	}
	else {
		printf("%d/%d", res + 2 -N, N);
	}
}
