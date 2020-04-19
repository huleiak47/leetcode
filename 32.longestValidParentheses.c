/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (27.95%)
 * Likes:    585
 * Dislikes: 0
 * Total Accepted:    50K
 * Total Submissions: 166.5K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 *
 * 示例 1:
 *
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 *
 *
 * 示例 2:
 *
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 *
 *
 */

// @lc code=start

#include <stdlib.h>
#include <string.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

typedef struct {
    int pairs;
    int leftPaCount;
} DpInfo;

int longestValidParentheses(char* s)
{
    int len = strlen(s);
    if (len <= 1) {
        return 0;
    }

    DpInfo* dp = (DpInfo*)malloc(len * sizeof(DpInfo));
    memset(dp, 0, len * sizeof(DpInfo));

    int max = 0;
    // i == 0
    if (s[0] == '(') {
        dp[0].leftPaCount = 1;
        dp[0].pairs       = 0;
    } else {
        dp[0].leftPaCount = 0;
        dp[0].pairs       = 0;
    }

    /*
    .... [i]
    当读取第i个字符时，操作如下：
    1. 如果是(，增加当前dp的左括号总数，对应的成对括号数为0
    2. 如果是)，有三种情况：
        a) 匹配前一个字节的(，这时成对括号数在 i-2 位置成对括号数的基础上加1
        b) 匹配前多个字节的(，这时相当于(....)，中间的这些字节一定是匹配的，所以在i-1位置的成对括号数上加1，这些由于前面
            的(之前可能还有配置的长度，所以要再加上(之前一个字节匹配数
        c) 多余的)，dp[i]清零，下一个i重新开始
    */
    for (int i = 1; i < len; i++) {
        if (s[i] == '(') {
            dp[i].leftPaCount = dp[i - 1].leftPaCount + 1;
            dp[i].pairs       = 0;
        } else {
            if (dp[i - 1].leftPaCount > 0) {
                dp[i].leftPaCount = dp[i - 1].leftPaCount - 1;
                if (s[i - 1] == '(') {
                    dp[i].pairs = 1 + (i - 2 >= 0 ? dp[i - 2].pairs : 0);
                } else {
                    dp[i].pairs = 1 + dp[i - 1].pairs;
                    if (i - dp[i].pairs * 2 >= 0) {
                        dp[i].pairs += dp[i - dp[i].pairs * 2].pairs;
                    }
                }
                max = Max(max, dp[i].pairs);
            } else {
                dp[i].leftPaCount = 0;
                dp[i].pairs       = 0;
            }
        }
    }
    free(dp);
    return max * 2;
}

// @lc code=end

#include <stdio.h>

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; i++) {
        printf("%d\n", longestValidParentheses(argv[i]));
    }
    return 0;
}
