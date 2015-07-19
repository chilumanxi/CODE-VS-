/*************************************************************************
    > File Name: 均分纸牌.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年06月19日 星期五 20时44分52秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int N;
int a[101];

int main(void){
	int sum = 0;
	int ans = 0;
	cin >> N;
	for(int i = 0; i < N; i ++){
		cin >> a[i];
		sum += a[i];
	}
	sum = sum / N;
	for(int i = 0; i < N - 1; i ++){
		if(a[i] != sum){
			a[i + 1] += a[i] - sum;
			ans ++;
		}
	}
	cout << ans << endl;
	return 0;
}
