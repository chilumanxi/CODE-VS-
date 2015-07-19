/*************************************************************************
    > File Name: 能量项链.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年07月18日 星期六 08时35分08秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int a[202];
int dp[202][202];
int ans = 0;

int main(void){
	cin >> N;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= N; i ++){
		cin >> a[i];
		a[N + i] = a[i];
	}
	for(int i = 1; i < N; i ++){
		for(int j = 1; i + j < 2 * N; j ++){
			int temp = 0;
			for(int k = j; k < i + j; k ++){
				temp = max(temp, dp[j][k] + dp[k + 1][i + j] + a[j] * a[k + 1] * a[i + j  + 1]);
			}
			dp[j][i + j] = temp;
		}
	}
	ans = 0;
	for(int i = 1; i <= N; i ++){
		ans = max(ans, dp[i][i + N - 1]);
	}
	cout << ans << endl;
	return 0;
}
