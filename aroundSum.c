//
// Created by cyq7on on 18-2-16.
//
/*
 * 矩阵求周边元素和，数值存储在一维数组中
 */
int aroundSum(int *a, int m, int n) {
    int sum = 0;
    for (int i = 0; i < m ; ++i) {
        for (int j = 0; j < n; ++j) {
//          二维数组形式时，行、列下标为0和最大值减一时即为周边元素
            if (i % m == 0 || j % n == 0 || i % m == m - 1 || j % n == n - 1) {
                sum += a[i *n +j];
            }
        }

    }
    return sum;
}