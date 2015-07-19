/*************************************************************************
    > File Name: 二叉树的序遍历.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com
    > Created Time: 2015年06月12日 星期五 21时56分09秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int a[20][2];
void find_front(int pos){
		printf("%d ", pos);
	if(a[pos][0] != 0){
		find_front(a[pos][0]);
	}
	if(a[pos][1] != 0){
		find_front(a[pos][1]);
	}
}

void find_middle(int pos){
    if(a[pos][0])
        find_middle(a[pos][0]);
    printf("%d ", pos);
    if(a[pos][1])
    find_middle(a[pos][1]);
    }

int find_last(int pos){
	if(a[pos][0] != 0){
		find_last(a[pos][0]);
	}
	if(a[pos][1] != 0){
		find_last(a[pos][1]);
	}
		printf("%d ", pos);
	return 0;
}

int main(void){
	int n;
	int i;
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	for(i = 1; i <= n; i ++){
		scanf("%d%d", &a[i][0], &a[i][1]);
	}
	find_front(1);
	printf("\n");
	find_middle(1);
	printf("\n");
	find_last(1);
}

