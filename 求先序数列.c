/*************************************************************************
    > File Name: 求先序数列.c
    > Author: zhanghaoran
    > Mail: 467908670@qq.com
    > Created Time: 2015年06月08日 星期一 22时21分39秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int tree(char *mid, char *last){
	char a, *p, *q;
	if(!*mid)
		return 0;
	p = last + strlen(last) - 1;
	printf("%c",*p);
	q = strchr(mid, *p);
	*p = 0;
	p = q - mid + last;
	a = *p;
	*p = 0;
	*q = 0;
	tree(mid, last);
	*p = a;
	tree(q + 1, p);
}

int main(void){
	char mid[100010];
	char last[100010];
	scanf("%s", mid);
	scanf("%s", last);
	tree(mid, last);
	printf("\n");
	return 0;
}

