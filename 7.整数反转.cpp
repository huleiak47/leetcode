/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (32.84%)
 * Likes:    1320
 * Dislikes: 0
 * Total Accepted:    182.7K
 * Total Submissions: 553.5K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 *
 * 示例 1:
 *
 * 输入: 123
 * 输出: 321
 *
 *
 * 示例 2:
 *
 * 输入: -123
 * 输出: -321
 *
 *
 * 示例 3:
 *
 * 输入: 120
 * 输出: 21
 *
 *
 * 注意:
 *
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 *
 */
#include <cstdint>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        bool neg = x < 0;
        int64_t _x = x;

        if (neg)
        {
            _x = -_x;
        }

        int threshold = 0x7fffffff / 10;

        int ret_val = 0;
        while (_x)
        {
            if (ret_val > threshold)
            {
                return 0;
            }
            ret_val = ret_val * 10 + _x % 10;
            if (ret_val < 0)
            {
                return 0;
            }
            _x /= 10;
        }

        return neg ? -ret_val : ret_val;

    }
};
