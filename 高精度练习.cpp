/*************************************************************************
    > File Name: 高精度练习.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年06月17日 星期三 12时46分56秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cstdio>
using namespace std;

char s1[501];
char s2[501];
char s3[501];

int t1[501];
int t2[501];
int t3[501];

struct node{
	int num[1010];
	int l;
};	

node a, b, c;
char s[1010];

int max(int a, int b){
	return a > b ? a : b;
}

int solve_plus(void){
	cin >> s1;
	cin >> s2;
	memset(t1, 0, sizeof(t1));
	memset(t2, 0, sizeof(t2));
	memset(t3, 0, sizeof(t3));
	int n1 = strlen(s1) - 1;
	int n2 = strlen(s2) - 1;
	if(n1 < n2 || (n1 == n2 && strcmp(s1, s2) < 0)){
		strcpy(s3, s1);
		strcpy(s1, s2);
		strcpy(s2, s3);
		cout << '-';
	}
	n1 = strlen(s1) - 1;
	n2 = strlen(s2) - 1;
	for(int i = 0; i <= n1; i ++){
		t1[i] = s1[n1 - i] - '0';
	}
	for(int i = 0; i <= n2; i ++){
		t2[i] = s2[n2 - i] - '0';
	}
	for(int i = 0; i <= n1; i ++){
		t3[i] = t1[i] - t2[i];
		if(t3[i] < 0){
			t3[i] += 10;
			t1[i + 1] --;
		}
	}
	while(t3[n1] == 0 && n1 > 0)
		n1 --;
	for(int i = n1; i >= 0; i --)
		cout << t3[i];
	return 0;
}

int solve_add(void){
	cin >> s1;
	cin >> s2;
	int n1 = strlen(s1) - 1;
	int n2 = strlen(s2) - 1;
	int ans = 0;
	for(int i = 0; i < max(n1, n2) + 1; i ++)
		s3[i] = '0';
	while(n1 >= 0 && n2 >= 0){
		if(s1[n1] - 48 + s2[n2] - 48 > 10){
			s3[ans] = s1[n1] + s2[n2] - 96 - 10;
			s3[ans + 1] += 1;
		}
		else 
			(s3[ans] = s1[n1] - 48 + s2[n2] - 48);
		n1 --;
		n2 --;
		ans ++;
	}
	if(n1 >= 0){
		for(int i = n1; i >= 0; i --){
			if(s3[ans] + s1[i] - 48 > 10){
				s3[ans] = s1[i] - 48 - 10;
				s3[ans + 1] += 1;
			}
			else{
				s3[ans] += s1[i] - 48;
			}
			ans ++;
		}
	}
	else{
		for(int i = n2; i >= 0; i --){
			if(s3[ans] + s2[i] - 48 > 10){
				s3[ans] = s2[i] - 48 - 10;
				s3[ans + 1] += 1;
			}
			else{
				s3[ans] += s2[i] - 48;
			}
			ans ++;
		}

	}
	for(int i = ans - 1; i >= 0; i --)
		printf("%d", s3[i]);
	return 0;
}

void solve_multiply(){
	memset(a.num, 0, sizeof(a.num));
	memset(b.num, 0, sizeof(b.num));
	memset(c.num, 0, sizeof(c.num));
	cin >> s;
	a.l = strlen(s);
	for(int i = 0; i < a.l; i ++){
		a.num[a.l - 1 - i] = s[i] - '0';
	}
	cin >> s;
	b.l = strlen(s);
	for(int i = 0; i < b.l; i ++){
		b.num[b.l - 1 - i] = s[i] - '0';
	}
	c.l = a.l + b.l;
	for(int i = 0; i < a.l; i ++){
		for(int j = 0; j < b.l; j ++){
			c.num[i + j] += a.num[i] * b.num[j];
		}
	}
	for(int i = 0; i < c.l; i ++){
		if(c.num[i] > 9){
			c.num[i + 1] += c.num[i] / 10;
			c.num[i] = c.num[i] % 10;
		}
	}
	while(c.l > 1 && c.num[c.l - 1] == 0)
		c.l --;
	for(int i = c.l - 1; i >= 0; i --)
		cout << c.num[i];
}

int main(void){
	solve_plus();
	return 0;
}
