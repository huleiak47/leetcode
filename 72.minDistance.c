/*
 * @lc app=leetcode.cn id=72 lang=c
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (53.70%)
 * Likes:    725
 * Dislikes: 0
 * Total Accepted:    45.4K
 * Total Submissions: 77.8K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 *
 * 你可以对一个单词进行如下三种操作：
 *
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 *
 *
 * 示例 2：
 *
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 *
 */

#include <stdio.h>
// @lc code=start

#include <stdlib.h>
#include <string.h>

int Min(int a, int b)
{
    return a < b ? a : b;
}

int minDistance(char* word1, char* word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int dpPrev[10000];
    int dp[10000];

    for (int i = 0; i <= len1; i++) {
        dpPrev[i] = i;
    }

    for (int i = 1; i <= len2; i++) {
        dp[0] = i;
        for (int j = 1; j <= len1; j++) {
            if (word1[j - 1] == word2[i - 1]) {
                dp[j] = dpPrev[j - 1];
            } else {
                dp[j] = Min(Min(dpPrev[j], dpPrev[j - 1]), dp[j - 1]) + 1;
            }
            // printf("%d, ", dp[j]);
        }
        // printf("\n");

        memcpy(dpPrev, dp, (len1 + 1) * sizeof(int));
    }

    return dpPrev[len1];
}

// @lc code=end

int main(int argc, char** argv)
{
    if (argc != 3) {
        return 0;
    }
    int ret = minDistance(argv[1], argv[2]);
    printf("%d\n", ret);
}
