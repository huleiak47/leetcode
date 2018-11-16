/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (34.29%)
 * Total Accepted:    361.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> stack;

        for (const char& c : s)
        {
            switch (c)
            {
            case '{':
                stack.push_back('}');
                break;
            case '[':
                stack.push_back(']');
                break;
            case '(':
                stack.push_back(')');
                break;
            case '}':
            case ']':
            case ')':
                if (stack.size() == 0 || *stack.rbegin() != c)
                {
                    return false;
                }
                stack.pop_back();
                break;
            default:
                break;
            }
        }
        return stack.size() == 0;
    }
};
