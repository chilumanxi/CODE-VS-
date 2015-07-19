/*************************************************************************
    > File Name: 传纸条.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年06月30日 星期二 20时17分03秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[51][51];
int dp[51][51][51][51];
int m ,n;
int dir[2][2] = {{-1, 0}, {0, -1}};
int maxof(int a, int b){
	return a > b ? a : b;
}
int main(void){
	cin >> m >> n;
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= m ; i ++){
		for(int j = 1; j <= n; j ++){
			cin >> a[i][j];
		}
	}
	memset(dp, 0, sizeof(dp));

	for(int i = 2; i <= m; i ++){
		for(int j = 1; j < n; j ++){
			for(int k = 1; k < i; k ++){
				for(int l = 2; l <= n; l ++){
					for(int d1 = 0; d1 < 2; d1 ++){
						for(int d2 = 0; d2 < 2; d2 ++){
							int ix = i + dir[d1][0];
							int jy = j + dir[d1][1];
							int kx = k + dir[d2][0];
							int ly = l + dir[d2][1];
							if(ix == kx && jy == ly)
								continue;
							dp[i][j][k][l] = maxof(dp[i][j][k][l] , dp[ix][jy][kx][ly]);
						}
					}
					dp[i][j][k][l] += a[i][j] + a[k][l];
				}
			}
		}
	}
	cout << dp[m][n - 1][m - 1][n] << endl;
	return 0;
}
