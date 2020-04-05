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
        ListNode root(0); // 占位用
        ListNode* curNode = &root;

        sort(lists.begin(), lists.end(), CompareNode);
        list<ListNode*> nodes;
        for (ListNode* node : lists) {
            if (node == nullptr) {
                continue;
            }
            nodes.push_back(node);
        }

        while (nodes.size() > 1) {
            curNode->next = *nodes.begin(); // 排序过的列表，第一个就是最小值
            nodes.erase(nodes.begin());     // 去掉第一个
            curNode        = curNode->next;
            ListNode* next = curNode->next;
            if (next != nullptr) { // 将第一个的下一节点插入到nodes中
                bool inserted = false;
                for (auto iter = nodes.begin(); iter != nodes.end(); ++iter) {
                    if (next->val < (*iter)->val) {
                        nodes.insert(iter, next);
                        inserted = true;
                        break;
                    }
                }
                if (!inserted) {
                    nodes.push_back(next);
                }
            }
        }
        if (nodes.size() == 1) {
            curNode->next = *nodes.begin();
        }

        return root.next; // root只是占位
    }
};
// @lc code=end
