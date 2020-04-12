/*
 * @lc app=leetcode.cn id=264 lang=c
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (51.08%)
 * Likes:    254
 * Dislikes: 0
 * Total Accepted:    22.1K
 * Total Submissions: 43.3K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 *
 * 丑数就是只包含质因数 2, 3, 5 的正整数。
 *
 * 示例:
 *
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 *
 * 说明:  
 *
 *
 * 1 是丑数。
 * n 不超过1690。
 *
 *
 */

// @lc code=start

#include <stdlib.h>

int Min(int a, int b)
{
    return a < b ? a : b;
}

int nthUglyNumber(int n)
{
    if (n <= 6) {
        return n;
    }
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= 6; ++i) {
        dp[i] = i;
    }

    int factors[] = {2, 3, 5};
    int cursors[] = {2, 2, 2}; // 分别存放2、3、5因子的起始扫描位置，这样不用每次从2开始
    for (int i = 7; i <= n; ++i) {
        // 将i之前的从cursor中开始的数分别乘以2,3,5，找到其中最小值就是下一个
        int min = INT_MAX;
        for (int m = 0; m < 3; ++m) {
            int fac = factors[m];
            for (int j = cursors[m]; j < i; ++j) {
                if (fac * dp[j] > dp[i - 1]) {
                    min        = Min(min, fac * dp[j]);
                    cursors[m] = j;
                    break;
                }
            }
        }
        dp[i] = min;
    }

    int ret = dp[n];
    free(dp);
    return ret;
}

// @lc code=end
