/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (62.03%)
 * Likes:    214
 * Dislikes: 0
 * Total Accepted:    49.7K
 * Total Submissions: 76.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 *
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 * 返回其自底向上的层次遍历为：
 *
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void iterNode(TreeNode* node, int depth, vector<vector<int>>& records)
    {
        if (!node) {
            return;
        }

        if (records.size() < depth + 1) {
            records.push_back(vector<int>());
        }

        records[depth].push_back(node->val);
        iterNode(node->left, depth + 1, records);
        iterNode(node->right, depth + 1, records);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> records;
        iterNode(root, 0, records);
        reverse(records.begin(), records.end());
        return records;
    }
};
// @lc code=end
