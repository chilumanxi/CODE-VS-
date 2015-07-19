/*************************************************************************
    > File Name: 数字三角形.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com
    > Created Time: 2015年07月02日 星期四 14时38分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int N;
long tower[101][101];
int temp = 0;
int main(void){
	cin >> N;
	for(int i = 1; i <= N; i ++){
		for(int j = 1; j <= i; j ++){
			cin >> tower[i][j];
			if(i > 1){
				if(j == 1)
					tower[i][j] += tower[i - 1][j];
				else if(j == i)
					tower[i][j] += tower[i - 1][j - 1];
				else
					tower[i][j] += max(tower[i - 1][j] , tower[i - 1][j - 1]);
			}
			if(i == N){
				if(temp < tower[i][j])
					temp = tower[i][j];
			}
		}
	}
	if(N == 1)
	temp = tower[1][1];
	cout << temp << endl;
	return 0;
}

