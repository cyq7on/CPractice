//
// Created by cyq7on on 18-2-16.
//

/*
 * 判断是否为回文字符串
 * 所谓回文，可以简单理解为字符串对称
 */

int isPalindromeStr(char *str) {
    int length = 0, i;
    while (str[length++]);
    length --;
    for (i = 0; i < length / 2; ++i) {
        if (str[i] != str[length - i - 1]) {
            break;
        }
    }
    return i == length / 2 ? 1 : 0;
}