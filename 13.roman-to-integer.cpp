/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (48.81%)
 * Total Accepted:    254.2K
 * Total Submissions: 520.7K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 *
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 *
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 *
 * Example 1:
 *
 *
 * Input: "III"
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: "IV"
 * Output: 4
 *
 * Example 3:
 *
 *
 * Input: "IX"
 * Output: 9
 *
 * Example 4:
 *
 *
 * Input: "LVIII"
 * Output: 58
 * Explanation: C = 100, L = 50, XXX = 30 and III = 3.
 *
 *
 * Example 5:
 *
 *
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 */

#include <string>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int i = 0;
        int len = s.size();
        const char* p = s.c_str();
        int val = 0;
        while (i < len)
        {
            switch (p[i])
            {
            case 'I': // 1
                if (i < len - 1)
                {
                    if (p[i + 1] == 'V')
                    {
                        val += 4;
                        i++;
                    }
                    else if (p[i + 1] == 'X')
                    {
                        val += 9;
                        i++;
                    }
                    else
                    {
                        val += 1;
                    }
                }
                else
                {
                    val += 1;
                }
                break;
            case 'V': // 5
                val += 5;
                break;
            case 'X': // 10
                if (i < len - 1)
                {
                    if (p[i + 1] == 'L')
                    {
                        val += 40;
                        i++;
                    }
                    else if (p[i + 1] == 'C')
                    {
                        val += 90;
                        i++;
                    }
                    else
                    {
                        val += 10;
                    }
                }
                else
                {
                    val += 10;
                }
                break;
            case 'L': // 50
                val += 50;
                break;
            case 'C': // 100
                if (i < len - 1)
                {
                    if (p[i + 1] == 'D')
                    {
                        val += 400;
                        i++;
                    }
                    else if (p[i + 1] == 'M')
                    {
                        val += 900;
                        i++;
                    }
                    else
                    {
                        val += 100;
                    }
                }
                else
                {
                    val += 100;
                }
                break;
            case 'D': // 500
                val += 500;
                break;
            case 'M': // 1000
                val += 1000;
                break;
            default:
                break;
            }
            i++;
        }
        return val;
    }
};
