//
// Created by cyq7on on 18-3-1.
//
#include <stdio.h>

#define N 5

typedef struct {
    int num;
    float score;
} Stu;

float sort(Stu *stu) {
    Stu tmp;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1 - i; ++j) {
            if (stu[j].score > stu[j + 1].score) {
                tmp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = tmp;
            }
        }
    }
    return (stu + N - 1)->score;
}

/*
void main() {
    float max;
    Stu stu[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d %f", &stu[i].num, &stu[i].score);
    }
    max = sort(stu);
    for (int j = N - 1; j >= 0; --j) {
        if (max == stu[j].score) {
            printf("学号%d分数%1f\n", stu[j].num, stu[j].score);
        } else {
            break;
        }
    }
}*/
