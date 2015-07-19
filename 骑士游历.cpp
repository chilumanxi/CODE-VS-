/*************************************************************************
    > File Name: 骑士游历.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年07月02日 星期四 13时57分30秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m;
int x1, x2, y1, y2;
long dp[51][51];

int main(void){
	cin >> n >> m;
	cin >> x1 >> y1 >> x2 >> y2;
	memset(dp, 0, sizeof(dp));
	dp[x1][y1] = 1;
	for(int i = x1 + 1; i <= x2; i ++){
		for(int j = 1; j <= m; j ++){
			if(j + 1 <= m && i - 2 >= 1)
				dp[i][j] += dp[i - 2][j + 1];
			if(j + 2 <= m)
				dp[i][j] += dp[i - 1][j + 2];
			if(j - 1 >= 1 && i - 2 >= 1)
				dp[i][j] += dp[i - 2][j - 1];
			if(j - 2 >= 1)
				dp[i][j] += dp[i - 1][j - 2];
		}
	}
	cout << dp[x2][y2] << endl;
	return 0;
}
