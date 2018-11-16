/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.38%)
 * Total Accepted:    439.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 
 */
class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;

        if (neg)
        {
            x = -x;
        }

        int threshold = 0x7fffffff / 10;
        
        int ret_val = 0;
        while (x)
        {
            if (ret_val > threshold)
            {
                return 0;
            }
            ret_val = ret_val * 10 + x % 10;
            if (ret_val < 0)
            {
                return 0;
            }
            x /= 10;
        }

        return neg ? -ret_val : ret_val;
    }
};
