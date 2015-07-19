/*************************************************************************
    > File Name: 四子连线.c
    > Author: zhanghaoran
    > Mail: 467908670@qq.com 
    > Created Time: 2015年05月26日 星期二 21时20分06秒
 ************************************************************************/

#include<stdio.h>

struct {
	int turn;
	int d;
	int fa;
	int x[2];
	int y[2];
	int chess[5][5];
}queue[100000],ext;

int che[5][5];
char chessboard[5][5];

int dirx[4] = {0, -1, 0, 1};
int diry[4] = {-1, 0. 1, 0};
int suc(){
	int i, j, temp = 0;
	if(queue[tail].chess[1][1] == queue[tail].chess[2][2] && queue[tail].chess[1][1] == queue[tail].chess[3][3] && queue[tail].chess[1][1] == queue[tail].chess[4][4])
		temp = 1;
	else if(queue[tail].chess[1][4] == queue[tail].chess[2][3] && queue[tail].chess[1][4] == queue[tail].chess[3][2] && queue[tail].chess[1][4] == queue[tail].chess[4][1])
		temp = 1;
	for(i = 0; i <= 4; i ++){
		if(queue[tail].chess[i][1] == queue[tail].chess[i][2] && queue[tail].chess[i][1] == queue[tail].chess[i][3] && queue[tail].chess[i][1] == queue[tail].chess[i][4]){
			temp = 1;
			break;	
		}
		if(queue[tail].chess[1][i] == queue[tail].chess[2][i] && queue[tail].chess[1][i] == queue[tail].chess[3][i] && queue[tail].chess[1][i] == queue[tail].chess[4][i]){
			temp = 1;
			break;
		} 	
	}
	return temp;
}

int check(int x, int y){
	int temp;
	int nowposx, nowposy;
	nowposx = ext.x[y] + dirx[x];
	nowposy = ext.y[y] + diry[x];
	if(nowposx >= 1 && nowposx <= 4 && nowposy >= 1 && nowposy <= 4 && ext.chess[nowposx][nowposy] == ext.turn &&  ext.chess[nowposx][nowposy] != 2)
		temp = 1;
	else temp = 0;
	return temp;
}

int change(){
	int i, j, k, temp = 1, d = 0;
	for(k = 1; k < tail; k ++){
		if(queue[k].turn != queue[tail].turn)
			for(i = 1; i <= 4; i ++)
				for(j = ; j <= 4; j ++)
					if(queue[k].chess[i][j] != queue[tail].chess[i][j])
						temp = 0;
		if(temp == 0)
			d = 1;
		temp = 1;
	}
	if(d == 0)
		return 1;
	else 
		return 0;
}

void bfs(){
	int i, j ,k = 1, x1, y1, x0, y0, dd, z;
	queue[1].d = 0;
	queue[1].fa = 0;
	queue[1].turn = 1;
	for(i = 1; i <= 4; i ++)
		for(j = 1; j <= 4; j ++){
			queue[1].chess[i][j] = che[i][j];
			if(che[i][j] == 2)
				queue[1].x[k] = 1;
				
		}
}

int main(void){
	int i, j,;
	for(i = 1; i < 4; i ++){
		for(j = 1; j < 4; j ++)
			scanf("%c", &chessboard[i][j]);
			scanf("%c\n", &chessboard[i][4]);
	}
	for(j = 1; j <=4; j ++)
		scanf("%c" ,&chessboard[4][i]);
	for(i = 0; i <= 4; i ++)
		for(j = 0; j <= 4; j ++)
			if(chessboard[i][j] == 'B')
				che[i][j] = 1;
			else if(chessboard[i][j] == 'W')
				che[i][j] = 0;
			else che[i][j] = 2;
}
