/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (50.06%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    35.5K
 * Total Submissions: 70.9K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ret  = "";
        int i       = 0;
        auto size_a = a.length();
        auto size_b = b.length();
        int carry   = 0;
        while (1)
        {
            int val_a = 0;
            int val_b = 0;

            if (i >= size_a && i >= size_b)
            {
                break;
            }

            if (i < size_a)
            {
                val_a = a[i] - '0';
            }

            if (i < size_b)
            {
                val_b = b[i] - '0';
            }

            switch (val_a + val_b + carry)
            {
            case 0:
                carry = 0;
                ret.push_back('0');
                break;
            case 1:
                carry = 0;
                ret.push_back('1');
                break;
            case 2:
                carry = 1;
                ret.push_back('0');
                break;
            case 3:
                carry = 1;
                ret.push_back('1');
                break;
            default:
                break;
            }
            i++;
        }

        if (carry)
        {
            ret.push_back('1');
        }

        if (ret == "")
        {
            ret = "0";
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};
