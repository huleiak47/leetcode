/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (47.35%)
 * Likes:    562
 * Dislikes: 0
 * Total Accepted:    92.2K
 * Total Submissions: 185.6K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 *
 * 示例:
 *
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
 *
 */

#include <vector>
#include <cstdint>
#include <cstdlib>
#include <algorithm>
using namespace std;

#ifndef NULL
#define NULL nullptr
#endif

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL)
    { }
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode root(0); // 占位用
        ListNode* curNode = &root;

        while (1) {
            int minIndex      = -1;
            int minVal        = (int)0x7fffffff;
            ListNode* minLink = nullptr;
            int nullCount     = 0;

            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] == nullptr) {
                    nullCount++;
                    continue;
                }
                if (lists[i]->val < minVal) {
                    minVal   = lists[i]->val;
                    minIndex = i;
                    minLink  = lists[i];
                }
            }
            if (nullCount == lists.size()) {
                break;
            }

            lists[minIndex] = lists[minIndex]->next;
            curNode->next   = minLink;
            curNode         = curNode->next;
        }

        return root.next; // root只是占位
    }
};
// @lc code=end
