/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.36%)
 * Likes:    453
 * Dislikes: 0
 * Total Accepted:    138K
 * Total Submissions: 315.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 *
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 *
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 *
 * 示例 1:
 *
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 *
 *
 * 示例 2:
 *
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 *
 *
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        vector<int> ret;
        int carry = 1; // 最低位加1，所以这里直接把进位设为1

        for (int i = digits.size() - 1; i >= 0; --i) {
            int val = digits[i] + carry;
            if (val > 9) {
                carry = 1;
                val -= 10;
            } else {
                carry = 0;
            }
            ret.push_back(val);
        }

        if (carry) {
            ret.push_back(1);
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};
// @lc code=end
