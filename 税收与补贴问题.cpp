/*************************************************************************
    > File Name: 税收与补贴问题.cpp
    > Author: zhanghaoran
    > Mail: 467908670@qq.com 
    > Created Time: 2015年05月22日 星期五 14时32分03秒
 ************************************************************************/

#include <stdio.h>

void swap(int &a, int &b){
	int t =a;
	a = b;
	b =t;
}

int abs(int a){
	if(a > 0)
		return a;
	else return -1*a;
}

int main(void){
	int Exp;
	int change_front, change_next;
	int a[100000], b[10000];
	int i = 0, j, k;
	int c[100000], d[100000];
	int x, y, z, h,e;
	int temp;
	int add =0, reduce = 0;
	scanf("%d", &Exp);
	while(1){
		scanf("%d %d", &a[i], &b[i]);
		if(a[i] == -1)
			break;
		else i ++;
	}
	for(j = 0; j < i; j ++){
		for(k = 1; k < i - j; k ++){
			if(a[k - 1] > a[k]){
				swap(a[k - 1], a[k]);
				swap(b[k - 1], b[k]);
			}
		}
	}
	scanf("%d", &change_next);
	c[0] = b[0];
	x = 1;
	y = a[0];
	z = b[0];
	for(j = 1; j < i; j++){
		if(a[j] != y + 1){
			change_front = abs(b[j] -z) / abs(a[j] - y);
			temp = 1;
			while( y != a[j]){
	 			c[x ++] = z - change_front * temp;
				temp ++;
				y ++;
			}
			z = b[j];
		}
		else{
			y = a[j];
			z = b[j];
			c[x ++] = b[j];
		}
	}
	x --;
	temp = 1;
	h = c[x];
	while(c[x] > 0){
		c[++ x] = h - change_next * temp;
		temp ++;
	}
	for(j = 0; j < x; j++){
		d[j] = a[0] ++;
	}
	for(j = 0; j < x; j++){
		if(d[j] == Exp)
			e = c[j];
	}
	for(j = 0; j < 100; j++){
		int max;
		max = (Exp - d[0] + j) * e;
		int flag = 0;
		for(int r = 0; r < x; r++){
			k = (d[r] - d[0] + j) * c[r];
			if(k > max){
				flag = 1;
	 			break;
			}
		}
		if(flag == 0){
			add = j;
			break;
		}
	}
	for(j = -1; j > -100; j --){
		int max = (Exp -d[0] + j) *e;
		int flag = 0;
		for(int r = 0; r < x; r ++){
			k  = (d[r] - d[0] + j)*c[r];
			if(k > max){
			flag = 1;
			break;
			}
		}
		if(flag == 0){
			reduce = j;
			break;
		}
	}
	if(add == reduce && add == 0)
		printf("NO SOLUTION");
	if(add == 0 && reduce != 0) printf("%d", reduce);
	if(add != 0 && reduce == 0) printf("%d", add);
	if(add != 0 && reduce != 0) printf("%d", add < reduce ? add : reduce);
	return 0;
}
	

