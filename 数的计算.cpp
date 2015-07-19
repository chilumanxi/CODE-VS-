/*************************************************************************
    > File Name: 数的计算.cpp
    > Author: zhanghaoran
    > Mail: 467908670@qq.com 
    > Created Time: 2015年05月21日 星期四 21时01分28秒
 ************************************************************************/

#include <stdio.h>

int count = 0;

void Caculate(int n){
	for(int i = 1; i <= n/2; i++){
		count ++;
		 Caculate(i);
	}
}

int main(void){
	int n;
	scanf("%d", &n);
	Caculate(n);
	printf("%d", count + 1);
	count = 0;
	return 0;
}

