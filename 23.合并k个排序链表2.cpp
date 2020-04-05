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
#include <list>
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

bool CompareNode(ListNode*& a, ListNode*& b)
{
    if (a == nullptr) {
        return false;
    }
    if (b == nullptr) {
        return true;
    }
    return a->val < b->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        switch (lists.size()) {
            case 0:
                return nullptr;
            case 1:
                return lists[0];
            default:
                break;
        }

        // 分治
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i += 2) {
                if (i + 1 < lists.size()) {
                    mergedLists.push_back(mergeTwoLists(lists[i], lists[i + 1]));
                } else {
                    mergedLists.push_back(lists[i]);
                }
            }
            lists = mergedLists;
        }

        return lists[0]; // root只是占位
    }

    ListNode* mergeTwoLists(ListNode* a, ListNode* b)
    {
        ListNode root(0);
        ListNode* curNode = &root;

        while (1) {
            if (a == nullptr && b == nullptr) {
                break;
            }
            if (a == nullptr) {
                curNode->next = b;
                break;
            }
            if (b == nullptr) {
                curNode->next = a;
                break;
            }

            if (a->val < b->val) {
                curNode->next = a;
                a             = a->next;
            } else {
                curNode->next = b;
                b             = b->next;
            }

            curNode = curNode->next;
        }

        return root.next;
    }
};
// @lc code=end
