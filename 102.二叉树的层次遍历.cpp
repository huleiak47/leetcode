/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (58.21%)
 * Likes:    432
 * Dislikes: 0
 * Total Accepted:    99.1K
 * Total Submissions: 161.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 *
 *
 *
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 * 返回其层次遍历结果：
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 *
 *
 */

// @lc code=start

#if 0
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {}
};
#endif

#include <vector>
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

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> records;
        iterNode(root, 0, records);
        return records;
    }
};
// @lc code=end
