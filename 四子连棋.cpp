/*************************************************************************
    > File Name: 四子连棋.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年07月20日 星期一 09时00分54秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct node{
    int map[5][5];
}q[10000];

int next[10000] = {1, 2};
int step[10000];
bool hash[5000000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int t = 0;
int w = 2;
bool flag = false;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

bool equ(int x1,int x2, int x3, int x4){
    if(x1 != x2 || x2 != x3 || x3 != x4 || x4 != x1)
        return false;
    else 
        return true;
}

bool check_end(){
    for(int i = 1; i <= 4; i ++){
        if(equ(q[w].map[i][1], q[w].map[i][2], q[w].map[i][3], q[w].map[i][4]))
            return true;
        if(equ(q[w].map[1][i], q[w].map[2][i], q[w].map[3][i], q[w].map[4][i]))
            return true;
    }
        if(equ(q[w].map[1][1], q[w].map[2][2], q[w].map[3][3], q[w].map[4][4]))
            return true;
        if(equ(q[w].map[4][1], q[w].map[3][2], q[w].map[2][3], q[w].map[1][4]))
            return true;
    return false;
}

bool Hash(){
    int s = 0;
    int temp = 1;
    for(int i = 1; i <= 4; i ++){
        for(int j = 1; j <= 4; j ++){
            s += q[w].map[i][j] * temp;
            temp *= 3;
        }
    }
    s %= 3733799;
    if(!hash[s]){
        hash[s] = true;
        return true;
    }
    else 
        return false;
}

bool check_move(int x, int y){
    int k = next[t];
    if(x > 4 || y > 4 || x == 0 || y == 0)
        return false;
    else if(q[t].map[x][y] == k)
        return true;
    return false;
}

void move(int x, int y){
    for(int i = 0; i < 4; i ++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(check_move(xx, yy)){
            for(int j = 1; j <= 4; j ++){
                for(int k = 1; k <= 4; k ++){
                    q[w].map[j][k] = q[t].map[j][k];
                }
            }
            swap(q[w].map[x][y], q[w].map[xx][yy]);
            step[w] = step[t] + 1;
            if(check_end()){
                cout << step[w] << endl; 
                flag = true;
                return ;
            }
            if(Hash()){
                if(next[t] == 1) 
                    next[w ++] = 2;
                else if(next[t] == 2)
                    next[w ++] = 1; 
            }
        }
    }
}


int main(void){
    char c;
    memset(q, 0, sizeof(q));
    for(int i = 1; i <= 4; i ++){
        for(int j = 1; j <= 4; j ++){
            cin >> c;
            if(c == 'W')
                q[0].map[i][j] = q[1].map[i][j] = 1;
            else if(c == 'B')
                q[0].map[i][j] = q[1].map[i][j] = 2;
        }
    }
    while(t < w){
        for(int i = 1; i <= 4; i ++){
            for(int j = 1; j <= 4; j ++){
                if(q[t].map[i][j] == 0)
                    move(i, j);
                if(flag)
                    return 0;
            }
        }
        t ++;
    }
}
