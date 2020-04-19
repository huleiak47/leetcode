/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (24.33%)
 * Likes:    1075
 * Dislikes: 0
 * Total Accepted:    65.4K
 * Total Submissions: 241.5K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 *
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 *
 *
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 *
 * 说明:
 *
 *
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 *
 *
 * 示例 1:
 *
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 *
 *
 * 示例 2:
 *
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a'
 * 重复了一次。
 *
 *
 * 示例 3:
 *
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 *
 *
 * 示例 4:
 *
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 *
 *
 * 示例 5:
 *
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 *
 */

// @lc code=start

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char c;
    int star;
} Pattern;

int dp[1001][1001];
Pattern ptn[1001] = {0};

bool isMatch(char* s, char* p)
{
    int lenS = strlen(s);
    int lenP = strlen(p);

    memset(ptn, 0, sizeof(ptn));
    memset(dp, 0, sizeof(dp));

    int ptnCount = 0;
    for (int i = 1; i <= lenP; i++) {
        ptn[ptnCount + 1].c = p[i - 1];
        if (i < lenP && p[i] == '*') {
            ptn[ptnCount + 1].star = true;
            i++;
        }
        ptnCount++;
    }

    dp[0][0] = true;
    for (int i = 1; i <= ptnCount; i++) {
        if (ptn[i].star && dp[0][i - 1]) {
            // 只有star能匹配空
            dp[0][i] = true;
        } else {
            dp[0][i] = false;
        }
    }

    for (int indexS = 1; indexS <= lenS; indexS++) {
        dp[indexS][0] = false;
        for (int indexP = 1; indexP <= ptnCount; indexP++) {
            if (ptn[indexP].star) {
                if (ptn[indexP].c != '.') {
                    dp[indexS][indexP] =
                        (ptn[indexP].c == s[indexS - 1])
                            ? (dp[indexS - 1][indexP] || dp[indexS - 1][indexP - 1] || dp[indexS][indexP - 1])
                            : dp[indexS][indexP - 1];
                } else {
                    dp[indexS][indexP] =
                        (dp[indexS - 1][indexP] || dp[indexS - 1][indexP - 1] || dp[indexS][indexP - 1]);
                }
            } else {
                if (ptn[indexP].c != '.') {
                    dp[indexS][indexP] = (ptn[indexP].c == s[indexS - 1]) ? dp[indexS - 1][indexP - 1] : false;
                } else {
                    dp[indexS][indexP] = dp[indexS - 1][indexP - 1];
                }
            }
        }
    }

    return (bool)dp[lenS][ptnCount];
}

// @lc code=end

int main(int argc, char** argv)
{
    bool ret = isMatch("ab", ".*c");
    if (ret) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
