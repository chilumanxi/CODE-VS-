/*************************************************************************
    > File Name: 四色问题.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年07月17日 星期五 11时07分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int N;
int map[9][9];
int flag[9];
int temp = 0;
int ans = 0;

void dfs(int num){
	if(num == N + 1){
		ans ++;
		return ;
	}
	for(int i = 1; i <= 4; i ++){
		for(int j = 1; j <= N; j ++){
			if(map[num][j] && flag[j] == i){
				temp = 1; 
				break;
			}
		}
		if(!temp){
			flag[num] = i;
			dfs(num + 1);
		}
		else
			temp = 0;
	}
	flag[num] = 0;
}

int main(void){
	cin >> N;
	for(int i = 1; i <= N; i ++){
		for(int j = 1; j <= N; j ++){
			cin >> map[i][j];
		}
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
