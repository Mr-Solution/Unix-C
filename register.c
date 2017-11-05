/*************************************************************************
	> File Name: register.c
	> Author: reeves
	> Mail: seereeves@163.com 
	> Created Time: 2017年11月05日 星期日 09时45分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct REG {
    int integ;
};

int main(void) {
    int *a;
    a = (int *)malloc(sizeof(int));
    *a = 5;
    printf("%d\n",*a);
    struct REG *r;
    r->integ = 10;
    printf("%d\n", r->integ);
    *a = r->integ;
    printf("%d\n", *a);
    r->integ = 0;
    printf("%d\n", *a);
    free(a);
    return 0;
}
