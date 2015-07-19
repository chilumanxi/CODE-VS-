/*************************************************************************
    > File Name: 乘积最大.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年07月06日 星期一 19时14分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <cstring>
using namespace std;

int N, K;
int n;
long long num[41][41];
char s[41];
long long dp[41][7];

int main(void){
	cin >> N >> K;
	cin >> s;
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < N; i ++){
		int temp = 0;
		for(int j = i; j < N; j ++){
			temp = temp * 10 + s[j] -'0';
			num[i][j] = temp;
		}
	}
	for(int i = 0; i < N; i ++){
		dp[i][0] = num[0][i];
	}
	for(int i = 0; i < N; i ++){
		for(int j = 1; j <= K; j ++){
			for(int k = 0; k < i; k ++){
				dp[i][j] = max(dp[k][j - 1] * num[k + 1][i], dp[i][j]);
			}
		}
	}
	cout << dp[N - 1][K] << endl;
	return 0;
}
