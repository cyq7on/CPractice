//
// Created by cyq7on on 18-2-15.
//


void bubble_sort(int *a, int n) {
    int temp;
    int i, j;
    int changed;
    for (i = 1; i < n; ++i) {
        changed = 0;
        for (j = 0; j < n - i; ++j) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                changed = 1;
            }
        }
        if (changed == 0) {
            break;
        }
    }
}