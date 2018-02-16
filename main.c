#include <stdio.h>
#include "common.h"

const int length = 6;

typedef struct stu {
    int age;
    float height;
} stu;

int main() {
//    冒泡排序
    /*int a[length];
    input_num(a,length);
    bubble_sort(a,length);
    output_num(a,length,2);*/

//  test sizeof
    /*stu s[3];
    printf("%d %d\n", sizeof(s[0].age), sizeof(s->height));
    printf("%d", sizeof(s));*/

//    回文字符测试
//    printf("%d",isPalindromeStr("abcdedcba"));
    int a[] ={3,0,0,3,2,5,7,3,1,0,4,2};

    printf("%d",aroundSum(a,3,4));
    return 0;
}
