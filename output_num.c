//
// Created by cyq7on on 18-2-16.
//

#include <stdio.h>

void output_num(int *a,int n,int col) {
    for (int i = 0; i < n; ++i) {
        if (i % col == 0) {
            printf("\n");
        }
        printf("%d\t",a[i]);
    }
}