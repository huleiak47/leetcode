/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (51.11%)
 * Likes:    169
 * Dislikes: 0
 * Total Accepted:    40.7K
 * Total Submissions: 75.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 *
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 * 返回锯齿形层次遍历如下：
 *
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
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
#ifdef LEETCODE_TEST
#define NULL nullptr

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {}
};
#endif

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void iterNode(vector<TreeNode*>& nodes, int depth, vector<vector<int>>& records)
    {
        if (nodes.empty()) {
            return;
        }

        if (records.size() < depth + 1) {
            records.push_back(vector<int>());
        }

        vector<TreeNode*> newNodes;
        if ((depth & 1) == 0) {
            for (TreeNode* node : nodes) {
                records[depth].push_back(node->val);
                if (node->left != nullptr) {
                    newNodes.push_back(node->left);
                }
                if (node->right != nullptr) {
                    newNodes.push_back(node->right);
                }
            }
        } else {
            for (TreeNode* node : nodes) {
                records[depth].push_back(node->val);
                if (node->right != nullptr) {
                    newNodes.push_back(node->right);
                }
                if (node->left != nullptr) {
                    newNodes.push_back(node->left);
                }
            }
        }

        nodes = newNodes;
        reverse(nodes.begin(), nodes.end());

        iterNode(nodes, depth + 1, records);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> records;
        vector<TreeNode*> nodes = {root};
        if (root != nullptr) {
            iterNode(nodes, 0, records);
        }
        return records;
    }
};
// @lc code=end
