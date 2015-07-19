/*************************************************************************
    > File Name: 明明的随机数.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com
    > Created Time: 2015年06月11日 星期四 19时54分10秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int M;

void quicksort(int a[], int left, int right, int n){
	int i, j, s, t;
	if(left < right){
		s = a[left];
		i = left;
		j = right;
		while(1){
			while(i + 1 < n && a[++i] < s);
			while(j - 1 > -1 && a[--j] > s);
			if(i >= j)
				break;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		a[left] = a[j];
		a[j] = s;
		quicksort(a, left, j ,  j );
		quicksort(a, j + 1, right, right);
	}
}

int main(void){
	int i, j, t;
	int res = 0;
	int a[101];
	scanf("%d", &M);
	for(i = 0; i < M; i ++){
		scanf("%d", &a[i]);
	}
	quicksort(a, 0, M, M);
	for(i = 0; i < M; i ++){
		 if(i > 0 && a[i] == a[i - 1]){
                a[i] = -1;
                t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
		 }

        else res ++;
	}
	printf("%d\n", res);
	for(i = 0; i < M; i++){
		if(a[i] != -1)
			printf("%d ", a[i]);
	}
}

