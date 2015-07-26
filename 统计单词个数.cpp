/*************************************************************************
	> File Name: 统计单词个数.cpp
	> Author: Zhanghaoran0
	> Mail: chiluamnxi@gmail.com
	> Created Time: 2015年07月25日 星期六 09时00分12秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, p, k, s;
string str;
string word[7];

int check[201][201];
int dp[201][201];
void DP();
void work(){
    bool flag;
    for(int j = str.size() - 1; j >= 0; j --){
        for(int i = j; i >= 0; i --){
            for(int l = 1; l <= s; l ++){
                flag = false;
                if(str.find(word[l], i) == i && word[l].size() <= j - i + 1){   //str.find(s, i)   从str这个串的第i个下标开始，寻找子字符串s，如果找到，返回s在str中的坐标。
                    flag = true;
                    break;
                }
            }
            if(flag){
                check[i][j] = check[i + 1][j] + 1;
            }
            else
                check[i][j] = check[i + 1][j];
        }
    }
    DP();
}

void DP(){
    for(int i = 0; i < str.size(); i ++){
        dp[i][1] = check[0][i];
    }
    for(int j = 2; j <= k; j ++){
        for(int i = j - 1; i < str.size(); i ++){
            for(int t = i - 1; t >= j - 1; t --){
                dp[i][j] = max(dp[i][j], dp[t][j - 1] + check[t + 1][i]);
            }
        }
    }
}

int main(void){
    freopen("in.txt", "r", stdin);
    string temp;
    memset(check, 0, sizeof(check));
    memset(dp, 0, sizeof(dp));
    cin >> n;
    while(n --){
        cin >> p >> k;
        str = "";
        while(p --){
            cin >> temp;
            str += temp;
        }
        cin >> s;
        for(int i = 1; i <= s; i ++){
            cin >> word[i];
        }
        work();
        cout << dp[str.size() - 1][k] << endl;
    }
    return 0;
}

