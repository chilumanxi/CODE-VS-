/*************************************************************************
    > File Name: 单词接龙.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年07月08日 星期三 19时22分00秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int N;
int a[21][21];
int flag[21];
int len[21];

char s[21][1000];
char t[5];

int dfs(int x){
	int length = len[x];
	int temp;
	for(int i = 1; i <= N; i ++){
		temp = 0;
		if(a[x][i] && flag[i] < 2){
			flag[i] ++;
			temp = dfs(i);
			flag[i] --;
			temp += len[x] - a[x][i];
		}
		if(temp > length)
			length = temp;
	}
	return length;
}

int main(void){
	int minlen, maxlen;
	int maxn = 0;
	cin >> N;
	for(int i = 1; i <= N; i ++){
		cin >> s[i];
		len[i] = strlen(s[i]);		
	}
	for(int i = 1; i <= N; i ++){
		for(int j = 1; j <= N; j ++){
			minlen = min(len[i], len[j]);		
			for(int k = 1; k <= minlen; k ++){
				if(strncmp(s[i] + len[i] - k, s[j], k) == 0){
					a[i][j] = k;
					break;
				}
			}
		}
	}
	cin >> t;
	for(int i = 1; i <= N; i ++){
		flag[i] = 0;
	}
	for(int i = 1; i <= N; i ++){
		if(s[i][0] == t[0]){
			flag[i] ++;
			maxn = max(maxn, dfs(i));
			flag[i] --;
		}
	}
	cout << maxn << endl;
	return 0;
}


