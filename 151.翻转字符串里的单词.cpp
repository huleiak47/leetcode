/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (29.39%)
 * Likes:    118
 * Dislikes: 0
 * Total Accepted:    38.4K
 * Total Submissions: 102.9K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给定一个字符串，逐个翻转字符串中的每个单词。
 *
 *
 *
 * 示例 1：
 *
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 *
 *
 * 示例 2：
 *
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 *
 *
 * 示例 3：
 *
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 *
 *
 *
 *
 * 说明：
 *
 *
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 *
 *
 *
 *
 * 进阶：
 *
 * 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 *
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start

struct Range {
    int start;
    int end;
    Range(int s, int e) : start(s), end(e)
    { }
};

class Solution {
public:
    string reverseWords(string s)
    {
        vector<Range> ranges;
        int len   = s.length();
        int start = 0;
        int end   = 0;
        int total = 0;
        while (1) {
            while (start < len && s[start] == ' ') {
                start++;
            }
            if (start == len) {
                break;
            }

            end = start + 1;
            while (end < len && s[end] != ' ') {
                end++;
            }
            ranges.push_back(Range(start, end));
            total += end - start;
            if (end == len) {
                break;
            }
            start = end + 1;
        }

        if (ranges.size() == 0) {
            return "";
        }
        total += ranges.size();
        total -= 1;
        string ret(total, ' ');
        char* from = s.data();
        char* to   = ret.data();
        for (auto iter = ranges.rbegin(); iter != ranges.rend(); ++iter) {
            memcpy(to, from + iter->start, iter->end - iter->start);
            to += iter->end - iter->start + 1;
        }
        return ret;
    }
};
// @lc code=end
