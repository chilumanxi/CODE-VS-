/*************************************************************************
    > File Name: 最大公约数和最小公倍数.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年06月12日 星期五 12时14分13秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>


int min(int x, int y){
	return x < y ? x : y;
}

int max(int x, int y){
	return x > y ? x : y;
}
int gcd(int x, int y){
	int i;
	for(i = min(x, y); i >= 1; i --){
		if(x % i == 0 && y % i == 0)
			return i;
	}
	return 0;
}

int lcm(int x, int y){
	int i;
	for(i = max(x, y); i <= x * y; i ++){
		if(i % x == 0 && i % y == 0)
			return i;
	}
	return 0;
}

int main(void){
	int i, j;
	int x0, y0;
	int res = 0;
	scanf("%d%d", &x0, &y0);
	for(i = x0; i <= y0; i ++){
		if(y0 % i == 0){
			j = y0/i * x0;
			if(gcd(i, j) == x0 && lcm(i, j) == y0)
				res ++;
		}
	}
	printf("%d\n", res);
}
