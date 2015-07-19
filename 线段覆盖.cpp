/*************************************************************************
    > File Name: 线段覆盖.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年06月19日 星期五 22时45分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int N;

pair<int , int> a[101];

int main(void){
	cin >> N;
	int ans = 0;
	for(int i = 0; i < N; i ++){
		cin >> a[i].second >> a[i].first;
		if(a[i].second > a[i].first)
			swap(a[i].second, a[i].first);
	}
	sort(a, a + N);
	int end = -9999;
	for(int i = 0; i < N; i ++){
		if(a[i].second >= end){
			end = a[i].first;
			ans ++;
		}
	}
	cout << ans << endl;
	return 0;
}
