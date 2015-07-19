/*************************************************************************
    > File Name: 进制转换.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年06月13日 星期六 12时55分28秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void HEX_to_other(int n, int x){
	int temp[200];
	int i = 0;
	while(n >= x){
		temp[i] = n % x;
		n /= x;
		i ++;
	}
	if(n == 15)
		printf("%c", 'F');
	else if(n == 14)
		printf("%c", 'E');
	else if(n == 13)
		printf("%c", 'D');
	else if(n == 12)
		printf("%c", 'C');
	else if(n == 11)
		printf("%c", 'B');
	else if(n == 10)
		printf("%c", 'A');
	else printf("%d", n);
	for(i = i - 1; i >= 0; i --){
		if(temp[i] == 15)
		printf("%c", 'F');
	else if(temp[i] == 14)
		printf("%c", 'E');
	else if(temp[i] == 13)
		printf("%c", 'D');
	else if(temp[i] == 12)
		printf("%c", 'C');
	else if(temp[i] == 11)
		printf("%c", 'B');
	else if(temp[i] == 10)
		printf("%c", 'A');
	else printf("%d", temp[i]);
	}
	
}

void other_to_HEX(char a[], int x){
	int t, i;
	int sum = 0;
	for(i = 0; i < strlen(a); i ++){
		if(a[i] >= '0' && a[i] <= '9'){
			t = a[i] - '0';
			sum = sum * x + t;	
		}
		else if(a[i] >= 'A' && a[i] <= 'F'){
			t = a[i] - 'A' + 10;
			sum = sum * x + t;
		}
		else{
			t = a[i] - 'a' + 10;
			sum = sum * x + t;
		}
	}
	printf("%d\n", sum);
}

int main(void){
	int x;
	char a[100];
	scanf("%s", a);
	scanf("%d", &x);
	other_to_HEX(a ,x);
	return 0;
}
