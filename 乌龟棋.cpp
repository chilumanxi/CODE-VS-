/*************************************************************************
    > File Name: 乌龟棋.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com
    > Created Time: 2015年06月22日 星期一 19时25分03秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int N, M;
int a[351];
int dp[50][50][50][50];
int x;
int b[5];
int main(void){
	cin >> N >> M;
	memset(dp, 0, sizeof(dp));
	memset(b, 0, sizeof(b));
	for(int i = 0; i < N; i++)
		cin >> a[i];
	for(int j = 0; j < M; j ++){
		cin >> x;
		b[x] ++;
	}
	dp[0][0][0][0] = a[0];
	for(int i = 0; i <= b[1]; i ++){
		for(int j = 0; j <= b[2]; j ++){
			for(int k = 0; k <= b[3]; k ++){
				for(int l = 0; l <= b[4]; l ++){
					if(i >= 1) dp[i][j][k][l] = dp[i][j][k][l] > dp[i - 1][j][k][l] + a[i + 2 * j + 3 * k + 4 * l] ? dp[i][j][k][l] : dp[i - 1][j][k][l] + a[i + 2 * j + 3 * k + 4 * l];
					if(j >= 1) dp[i][j][k][l] = dp[i][j][k][l] > dp[i][j - 1][k][l] + a[i + 2 * j + 3 * k + 4 * l] ? dp[i][j][k][l] : dp[i][j - 1][k][l] + a[i + 2 * j + 3 * k + 4 * l];
					if(k >=1) dp[i][j][k][l] = dp[i][j][k][l] > dp[i][j][k - 1][l] + a[i + 2 * j + 3 * k + 4 * l] ? dp[i][j][k][l] : dp[i][j][k - 1][l] + a[i + 2 * j + 3 * k + 4 * l];
					if(l >= 1) dp[i][j][k][l] = dp[i][j][k][l] > dp[i][j][k][l - 1] + a[i + 2 * j + 3 * k + 4 * l] ? dp[i][j][k][l] : dp[i][j][k][l - 1] + a[i + 2 * j + 3 * k + 4 * l];
				}
			}
		}
	}
	cout << dp[b[1]][b[2]][b[3]][b[4] ] << endl;
	return 0;
}

