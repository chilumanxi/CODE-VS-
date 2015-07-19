/*************************************************************************
    > File Name: 单词反转.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年06月11日 星期四 19时48分06秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
   char  a[100];
   char b[100];
   int i = 0;
   int j;
   int temp = 0;
   gets(a);
   for(i = strlen(a); i >= -1; i --){
        if(a[i] == 32 || i == -1){
            for(j = 1; i + j < strlen(a)&&a[i + j] != 32; j ++){
                b[temp] = a[i +j];
                temp ++;
            }
            b[temp] = 32;
            temp ++;
    }
   }
   b[temp] = '\0';
   printf("%s", b);
    return 0;
}

