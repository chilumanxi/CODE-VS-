/*************************************************************************
    > File Name: 过河卒.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com
    > Created Time: 2015年06月30日 星期二 19时02分51秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

int mx, my;
int dp[16][16];
int bx, by;

int main(void){
	cin >> bx >> by >> mx >> my;
	for(int i = 0; i <= bx; i ++){
		for(int j = 0; j <= by; j ++){
			dp[i][j] = 1;
		}
	}
 if(mx - 2 >= 0 && my - 1 >= 0){
		dp[mx - 2][my - 1] = 0;
	}
	if(mx + 2 <= bx && my - 1 >= 0){
		dp[mx + 2][my - 1] = 0;
	}
	if(mx + 2 <= bx && my + 1 <= by){
		dp[mx + 2][my + 1] = 0;
	}
	if(mx - 2 >= 0 && my + 1 <= by){
		dp[mx - 2][my + 1] = 0;
	}
	if(mx - 1 >= 0 && my - 2 >= 0){
		dp[mx - 1][my - 2] = 0;
	}
	if(mx - 1 >= 0 && my + 2 <= by){
		dp[mx - 1][my + 2] = 0;
	}
	if(mx + 1 <= bx && my - 2 >= 0){
		dp[mx + 1][my - 2] = 0;
	}
	if(mx + 1 <= bx && my + 2 <= by){
		dp[mx + 1][my + 2] = 0;
	}
	dp[mx][my] = 0;
 	for(int i = 0; i <= bx; i ++){
		for(int j = 0; j <= by; j ++){
			if(!dp[i][j])
				continue;
			else if(i == 0 && j == 0)
				continue;
 			else if(i == 0)
				dp[i][j] = dp[i][j - 1];
			else if(j == 0)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[bx][by] << endl;
	return 0;
}

