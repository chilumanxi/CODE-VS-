/*************************************************************************
    > File Name: 石子合并.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年06月22日 星期一 22时34分28秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>

#define INF 10000000

using namespace std;


int dp[101][101];
int sum[101];
int m[101];
int n;

int main(void){
	cin >> n;
	sum[0] = 0;
	for(int i = 1; i <= n; i ++){
		cin >> m[i];
		sum[i] = sum[i - 1] + m[i];
		dp[i][i] = 0;
	}
	for(int t = 2; t <= n; t ++){
		for(int i = 1; i <= n - t + 1; i ++){
			int j = i + t - 1;
			int MAX = INF;
			for(int k = i; k < j; k ++){
				if(MAX > dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1])
					MAX = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
			}
			dp[i][j] = MAX;
		}
	}
	cout << dp[1][n];
	return 0;
}
