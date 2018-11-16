/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.76%)
 * Total Accepted:    295.9K
 * Total Submissions: 931.4K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
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
