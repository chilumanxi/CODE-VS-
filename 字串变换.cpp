/*************************************************************************
    > File Name: 字串变换.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年07月22日 星期三 08时41分10秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
using namespace std;

char s1[6][21];
char s2[6][21];

struct node{
	char s[40];
	int step;
}q1[10000], q2[10000];

int head1 = 0, tail1 = 1;
int head2= 0, tail2 = 1;
int l1[6], l2[6];
int n;
void bfs1(int begin, int cur){
	int i , j;
	q1[tail1].step = q1[head1].step + 1;
	for(i = 0; i < begin; i ++){
		q1[tail1].s[i] = q1[head1].s[i];
	}
	for(j = 0; s2[cur][j] != '\0'; i ++, j ++){
		q1[tail1].s[i] = s2[cur][j];
	}
	for(j = begin + strlen(s1[cur]); q1[head1].s[j] != '\0'; j ++, i ++){
		q1[tail1].s[i] = q1[head1].s[j];
	}
	q1[tail1].s[i] = '\0';
	for(i = 0; i <= tail1; i++){
		if(strcmp(q2[i].s, q1[tail1].s) == 0){
			printf("%d\n", q2[i].step + q1[tail1].step);
			exit(0);
		}
	}
	tail1 ++;	
}

void bfs2(int begin, int cur){
	int i, j;
	q2[tail2].step = q2[head2].step + 1;
	for(i = 0; i < begin; i ++){
		q2[tail2].s[i] = q2[head2].s[i];
	}
	for(j = 0; s1[cur][j] != '\0'; j ++, i ++){
		q2[tail2].s[i] = s1[cur][j];
	}
	for(j = begin + strlen(s2[cur]); q2[head2].s[j] != '\0'; j ++, i ++){
		q2[tail2].s[i] = q2[head2].s[j];
	}
	q2[tail2].s[i] = '\0';
	for(i = 0; i <= tail2; i ++){
		if(strcmp(q2[tail2].s, q1[i].s) == 0){
			printf("%d\n", q1[i]. step + q2[tail2].step);
			exit(0);
		}
	}
	tail2 ++;
}


int main(void){
	scanf("%s%s", q1[0].s, q2[0].s);
	while(scanf("%s%s", s1[n], s2[n]) == 2)
		n ++;
	while(head1 < tail1 && head2 < tail2){
		if(q1[head1].step + q2[head2].step > 10){
			printf("NO ANSWER!\n");
			return 0;
		}
		for(int i = 0; i < strlen(q1[head1].s); i ++){
			for(int j = 0; j < n; j ++){
				if(strncmp(s1[j], &q1[head1].s[i], strlen(s1[j])) == 0){
					bfs1(i, j);
				}
			}
		}
		head1 ++;
		for(int i = 0; i < strlen(q2[head2].s); i ++){
			for(int j = 0; j < n; j ++){
				if(strncmp(s2[j], &q2[head2].s[i], strlen(s2[j])) == 0){
					bfs2(i, j);
				}
			}
		}
		head2 ++;
	}
	printf("NO ANSWER!\n");
	exit(0);
}
