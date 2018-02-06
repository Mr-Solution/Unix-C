/*************************************************************************
	> File Name: chapter2.c
	> Author: strider
	> Mail: strider92@foxmail.com 
	> Created Time: 2018年01月30日 星期二 20时26分55秒
 ************************************************************************/

#include<stdio.h>
#include<limits.h>
#include<float.h>
int main() {
    printf("char 变量长度: %d\n",CHAR_BIT);
    printf("char 变量取值范围为:%d~%d\n",CHAR_MIN,CHAR_MAX);
    unsigned char uc = ~0;
    uc = uc >> 1; 
    printf("signed char min = %d\n",-uc);
    printf("signed char max = %d\n",uc);
    return 0;
}
