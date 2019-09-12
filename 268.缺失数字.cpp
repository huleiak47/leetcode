/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 *
 * https://leetcode-cn.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (52.06%)
 * Likes:    154
 * Dislikes: 0
 * Total Accepted:    28.8K
 * Total Submissions: 55.3K
 * Testcase Example:  '[3,0,1]'
 *
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 * 
 * 示例 1:
 * 
 * 输入: [3,0,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [9,6,4,2,3,5,7,0,1]
 * 输出: 8
 * 
 * 
 * 说明:
 * 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 * 
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        /*
        0 ~ n 的总和为 0 + 1 + 2 + ... + n
        0 ~ n 的总和与数组中所有元素的总和之差就是缺的那个数
        */
       int sum1 = 0;
        for (int val: nums)
        {
            sum1 += val;
        }
        int n = nums.size();

        int sum2 = ((1 + n) * n) >> 1;

        return sum2 - sum1;
    }
};
