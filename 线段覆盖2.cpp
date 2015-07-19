/*************************************************************************
    > File Name: 线段覆盖2.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年07月19日 星期日 08时33分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
struct  node{
	int s;
	int e;
	int v;
}q[1001];

int dp[1000];
int ans = 0;

int cmp(const node x, const node y){
	return x.e < y.e;
}
int main(void){
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> q[i].s >> q[i].e >> q[i].v;
	}
	sort(q, q + n, cmp);
	int ans  = 0;
	for(int i = 1; i < n; i ++){
		int temp = 0;
		for(int j = 0; j < i; j ++){
			if(q[i].s >= q[j].e){
				if(temp < q[j].v)
					temp = q[j].v;
			}
		}
		q[i].v = q[i].v + temp;
		if(ans < q[i].v){
			ans = q[i].v;
		}
	}
	cout << ans << endl;
	return 0;
}
