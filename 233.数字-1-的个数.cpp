/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 *
 * https://leetcode-cn.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (29.71%)
 * Likes:    63
 * Dislikes: 0
 * Total Accepted:    2.6K
 * Total Submissions: 8.6K
 * Testcase Example:  '13'
 *
 * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
 *
 * 示例:
 *
 * 输入: 13
 * 输出: 6
 * 解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
 *
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n)
    {
        if (n <= 0) {
            return 0;
        }
        int count  = 0;
        int base   = 1;
        int mod    = n % 10;
        int shang  = n / 10;
        int lowVal = 0;

        while (1) {
            count += (base * shang);
            switch (mod) {
                case 0:
                    break;
                case 1:
                    count += lowVal + 1;
                    break;
                default:
                    count += base;
            }

            if (shang == 0) {
                break;
            }

            lowVal += mod * base;
            base *= 10;
            mod   = shang % 10;
            shang = shang / 10;
        }

        return count;
    }
};
// @lc code=end
