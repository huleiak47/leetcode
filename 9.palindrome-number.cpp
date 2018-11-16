/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (37.20%)
 * Total Accepted:    358.4K
 * Total Submissions: 963.6K
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;

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

        return ret_val;
    }

    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }

        if (x < 10)
        {
            return true;
        }

        return reverse(x) == x;
    }
};
