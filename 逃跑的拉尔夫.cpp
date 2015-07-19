/*************************************************************************
    > File Name: 逃跑的拉尔夫.cpp
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年07月19日 星期日 15时31分35秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int R, C;
int map[60][60];
char MAP[60][60];
int N;
char s[10];
int turn[1001];
int vis[60][60][1001];
int sx, sy;
struct node{
	int posx;
	int posy;
	int step;
}q[10000000];
int head = 0, tail = 1;


void bfs(){
	q[0].posx = sx;
	q[0].posy = sy;
	q[0].step = 0;
	while(head < tail){
		int m = q[head].step + 1;
		int dir = turn[m];
		int i = q[head].posx;
		int j = q[head].posy;
		while(m <= N){
			if(dir == 1)
				i --;
			if(dir == 2)
				i ++;
			if(dir == 3)
				j --;
			if(dir == 4)
				j ++;
			if(i <= R && j <= C && map[i][j]){
				if(!vis[i][j][m]){
					q[tail].posx = i;
					q[tail].posy = j;
					q[tail].step = m;
					vis[i][j][m] = 1;
					tail ++;
				}
			}
			else break;
		}
		head ++;
	}

}

int main(void){
	memset(map, 0, sizeof(map));
	cin >> R >> C;
	for(int i = 1; i <= R; i ++){
		cin >> s;
		for(int j = 0; j < C; j ++){
			if(s[j] == '.')
				map[i][j + 1] = 1;
			else if(s[j] == '*'){
				sx = i;
				sy = j + 1;
				map[i][j + 1] = 1;
			}
		}
	}
	cin >> N;
	for(int i = 1; i <= N; i ++){
		cin >> s;
		if(!strcmp(s, "NORTH"))
			turn[i] = 1;
		else if(!strcmp(s, "SOUTH"))
			turn[i] = 2;
		else if(!strcmp(s, "WEST"))
			turn[i] = 3;
		else turn[i] = 4;
	}
	bfs();
	for(int i = 1; i <= R; i ++){
		for(int j = 1; j <= C; j ++){
			if(map[i][j] == 0)
				printf("X");
			else if(vis[i][j][N])
				printf("*");
			else 
				printf(".");
		}
		printf("\n");
	}
	return 0;
}
