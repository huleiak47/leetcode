/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 *
 * https://leetcode-cn.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (41.88%)
 * Likes:    80
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 19.7K
 * Testcase Example:  '["i", "love", "leetcode", "i", "love", "coding"]\n2'
 *
 * 给一非空的单词列表，返回前 k 个出现次数最多的单词。
 *
 * 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
 *
 * 示例 1：
 *
 *
 * 输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * 输出: ["i", "love"]
 * 解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
 * ⁠   注意，按字母顺序 "i" 在 "love" 之前。
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"],
 * k = 4
 * 输出: ["the", "is", "sunny", "day"]
 * 解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
 * ⁠   出现次数依次为 4, 3, 2 和 1 次。
 *
 *
 *
 *
 * 注意：
 *
 *
 * 假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
 * 输入的单词均由小写字母组成。
 *
 *
 *
 *
 * 扩展练习：
 *
 *
 * 尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。
 *
 *
 */

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// @lc code=start

struct Record {
    const string* s;
    int count;
    Record(const string* s, int count) : s(s), count(count)
    { }
};

bool Compare(const Record& a, const Record& b)
{
    if (a.count > b.count) {
        return true;
    } else if (a.count == b.count) {
        return *a.s < *b.s;
    }
    return false;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int> map;

        for (auto& s : words) {
            if (map.count(s) == 0) {
                map[s] = 1;
            } else {
                map[s] = map[s] + 1;
            }
        }

        vector<Record> records;
        for (auto iter = map.begin(); iter != map.end(); ++iter) {
            records.push_back(Record(&(iter->first), iter->second));
        }

        sort(records.begin(), records.end(), Compare);

        vector<string> ret;

        for (int i = 0; i < k; ++i) {
            ret.push_back(*records[i].s);
        }

        return ret;
    }
};
// @lc code=end
