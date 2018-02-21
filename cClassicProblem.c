//
// Created by cyq7on on 18-2-18.
//

/*
 * c语言经典算法题
 */

/*
题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
程序分析：对n进行分解质因数，应先找到一个最小的质数k，然后按下述步骤完成：
(1)如果这个质数恰等于n，则说明分解质因数的过程已经结束，打印出即可。
(2)如果n<>k（不等于），但n能把k整除，则应打印出k的值，并用n除以k的商,作为新的正整数n,重复执行这步。
(3)如果n不能把k整除，则用k+1作为k的值,重复执行第一步，这里用一个while循环直到k==n跳出循环。*/

#include <stdio.h>

void getNum(int n) {
    printf("%d=", n);
    for (int i = 2; i <= n; ++i) {
        while (i != n) {
            if (n % i == 0) {
                printf("%d*", i);
                n /= i;
            } else {
                break;
            }
        }
    }
    printf("%d", n);
}


/*题目：一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6=1＋2＋3.*/
void getWanshu(int max) {
    int target;
    for (int i = 2; i <= max; ++i) {
        target = i;
        for (int j = 1; j < i; ++j) {
            if (i % j == 0) {
                target -= j;
            }
        }
        if (target == 0) {
            printf("%d是完数\n", i);
        }
    }
}

/*题目：有n个整数，使其前面各数顺序向后移，使得最后m个数变成最前面的m个数*/

void move() {
    int n, m;
    printf("请输入整数个数n");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        printf("请输入第%d个数", i + 1);
        scanf("%d", &a[i]);
    }
    printf("请输入m");
    scanf("%d", &m);

    exchange(a, 0, n - m - 1);
    exchange(a, n - m, n - 1);
    exchange(a, 0, n - 1);
    for (int k = 0; k < n; ++k) {
        printf("%d\t", a[k]);
    }
}

void exchange(int *a,int start, int end) {
    int tmp;
    for (int j = 0; j <= (end - start) / 2; ++j) {
        tmp = a[end - j];
        a[end - j] = a[start + j];
        a[start + j] = tmp;
    }
}

void main() {
//    getNum(90);

//    getWanshu(1000);

    move();
}