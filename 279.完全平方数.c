/*
 * @lc app=leetcode.cn id=279 lang=c
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (55.40%)
 * Likes:    376
 * Dislikes: 0
 * Total Accepted:    49.6K
 * Total Submissions: 89.4K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 *
 * 示例 1:
 *
 * 输入: n = 12
 * 输出: 3
 * 解释: 12 = 4 + 4 + 4.
 *
 * 示例 2:
 *
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 *
 */

// @lc code=start
#include <stdlib.h>

int Min(int a, int b)
{
    return a < b ? a : b;
}

int numSquares(int n)
{
    if (n <= 3) {
        return n;
    }
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0]   = 0;
    dp[1]   = 1;
    dp[2]   = 2;
    dp[3]   = 3;

    for (int i = 4; i <= n; ++i) {
        dp[i] = INT_MAX;
    }

    int i = 2;
    while (1) {
        int sqrN = i * i;
        if (sqrN > n) {
            break;
        } else if (sqrN == n) {
            return 1;
        }
        dp[sqrN] = 1;
        i++;
    }

    for (int i = 4; i <= n; ++i) {
        if (dp[i] == 1) {
            continue;
        }
        int min = INT_MAX;
        int j   = 1;
        while (1) {
            int sq = j * j;
            if (sq > i) {
                break;
            }
            min = Min(min, dp[i - sq] + 1);
            j++;
        }
        dp[i] = min;
    }
    int ret = dp[n];
    free(dp);
    return ret;
}

// @lc code=end
