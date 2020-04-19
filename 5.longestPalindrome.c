/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.66%)
 * Likes:    1957
 * Dislikes: 0
 * Total Accepted:    224.6K
 * Total Submissions: 768.8K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 示例 1：
 *
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 *
 *
 * 示例 2：
 *
 * 输入: "cbbd"
 * 输出: "bb"
 *
 *
 */

// @lc code=start

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

int dp[1000][1000] = {0};

char* longestPalindrome(char* s)
{
    int len = strlen(s);
    if (len == 0) {
        return s;
    }

    int max = INT_MIN;
    int cur = -1;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (s[len - 1 - i] == s[j]) {
                dp[i][j] = (i > 0 && j > 0) ? dp[i - 1][j - 1] + 1 : 1;
            } else {
                dp[i][j] = 0;
            }
            // 必须正好横跨dp右上-左下对角线才是合法的，说明他们有共同的中点
            if (max <= dp[i][j] && j == (len - 1 - 1 - (i - dp[i][j]))) {
                max = dp[i][j];
                cur = j;
            }
        }
    }

    // for (int i = 0; i < len; i++) {
    //     for (int j = 0; j < len; j++) {
    //         printf("%d, ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("max = %d, cur = %d\n", max, cur);

    char* ret = (char*)malloc(max + 1);
    ret[max]  = '\0';
    memcpy(ret, s + cur + 1 - max, max);
    return ret;
}

// @lc code=end

#include <stdio.h>

int main()
{
    char* s   = "babd";
    char* ret = longestPalindrome(s);
    printf("%s", ret);
    return 0;
}
