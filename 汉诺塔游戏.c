/*************************************************************************
    > File Name: 汉诺塔游戏.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年06月13日 星期六 12时11分44秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int res = 0;

void hanoi_check(char a, char b, char c, int n){
	if(n == 1){
		res ++;
	}
	else{
		hanoi_check(a, c, b, n - 1);
		res ++;
		hanoi_check(b, a, c, n - 1);
	}
}

void hanoi_put(char a, char b, char c, int n){
	if(n == 1){
		printf("%d from %c to %c\n", n, a, c);
	}
	else{
		hanoi_put(a, c, b, n - 1);
		printf("%d from %c to %c\n", n, a, c);
		hanoi_put(b, a, c, n - 1);
	}
}	

int main(void){
	int n;
	scanf("%d", &n);
	hanoi_check('A', 'B', 'C', n);
	printf("%d\n", res);
	hanoi_put('A', 'B', 'C', n);
}
