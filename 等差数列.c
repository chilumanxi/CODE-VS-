/*************************************************************************
    > File Name: 等差数列.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com
    > Created Time: 2015年06月09日 星期二 18时19分07秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int n;
int dp[101];

void swap(int *a, int *b){
	int *t = a;
	a = b;
	b = t;
}

void quicksort(int a[], int left, int right){
	int i, j, s, t;
	if(left < right){
		s = a[right];
		i = left - 1;
		for(j = left; j < right; j ++){
			if(a[j] <= s){
				t = a[++i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		t = a[right];
		a[right] = a[i + 1];
		a[i + 1] = t;
		quicksort(a, left, i);
		quicksort(a, i + 2, right);
	}
}
int solve(int a[]){
	int i, j;
	int max = 0, res = 0;
	int temp;
	int t, s;
	for(i = 0; i < n - 1; i ++){
		for(j = i + 1; j < n; j ++){
			temp = a[j] - a[i];
			t = j;
			s = i;
			while(t < n){
				if(a[t] - a[s] == temp){
					s = t;
					t ++;
					res ++;
				}
				else t ++;
			}
			max = max > res ? max : res;
			res = 0;
		}
	}
	return max;
}


int main(void){
	int i, j;
	int a[101];
	scanf("%d", &n);
	for(i = 0; i < n; i ++){
		scanf("%d", &a[i]);
	}
	quicksort(a, 0, n - 1);
	printf("%d\n", solve(a) + 1);
	return 0;
}
