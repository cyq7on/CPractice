//
// Created by cyq7on on 18-2-16.
//
#include <stdio.h>

void input_num(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("请输入第%d个数", i + 1);
        scanf("%d",&a[i]);
    }
}