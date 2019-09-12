/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.46%)
 * Likes:    694
 * Dislikes: 0
 * Total Accepted:    120.8K
 * Total Submissions: 347.7K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        if (strs.size() == 0)
        {
            return "";
        }
        while (1)
        {
            if (i == strs[0].size())
            {
                return strs[0];
            }
            char x = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (i == strs[j].size())
                {
                    return strs[j];
                }

                if (strs[j][i] != x)
                {
                    return string(&strs[0][0], &strs[0][i]);
                }
            }
            i++;
        }
    }
};
