/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (39.81%)
 * Likes:    237
 * Dislikes: 0
 * Total Accepted:    63.3K
 * Total Submissions: 151K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 *
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * 示例:
 *
 * 给定二叉树 [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * 返回它的最小深度  2.
 *
 */

// @lc code=start

#ifdef LEETCODE_TEST
#define NULL nullptr
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {}
};
#endif

#include <queue>

using namespace std;

struct Record {
    TreeNode* node;
    int depth;
    Record(TreeNode* node, int depth) : node(node), depth(depth)
    {}
};

class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        queue<Record> records;
        records.push(Record(root, 1));
        while (!records.empty()) {
            auto& rec = records.front();
            if (rec.node->left == nullptr && rec.node->right == nullptr) {
                return rec.depth;
            }

            if (rec.node->left != nullptr) {
                records.push(Record(rec.node->left, rec.depth + 1));
            }
            if (rec.node->right != nullptr) {
                records.push(Record(rec.node->right, rec.depth + 1));
            }
            records.pop();
        }
        return 0;
    }
};
// @lc code=end
