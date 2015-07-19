/*************************************************************************
    > File Name: 数的划分.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年07月14日 星期二 19时56分03秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int n, k;
int dp[201][7];


int main(void){
	cin >> n >> k;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i  = 1; i <= n; i ++){
		for(int j = 1; j <= k; j ++){
			if(i >= j){
				dp[i][j] = dp[i- j][j] + dp[i - 1][j - 1];
			}
		}
	}
	cout << dp[n][k] << endl;
}
