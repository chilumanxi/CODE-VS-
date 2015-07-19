/*************************************************************************
    > File Name: 全排列.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年07月17日 星期五 11时41分21秒
 ************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

int n;
int flag[11];
int parr[11];

void dfs(int num){
	if(num == n + 1){
	 	for(int i = 1; i <= n; i ++){
			cout << parr[i] << " ";
		}
		cout << endl;
		return ;
	}
	for(int i = 1; i <= n; i ++){
		if(flag[i])
			continue;
		parr[num] = i;
		flag[i] = 1;
		dfs(num + 1);
		flag[i] = 0;
	}
	return ;
}

int main(void){
	memset(flag,0,sizeof(flag));
        memset(parr,0,sizeof(parr));
	cin >> n;
	dfs(1);
	return 0;
}
