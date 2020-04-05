/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (60.46%)
 * Likes:    157
 * Dislikes: 0
 * Total Accepted:    23K
 * Total Submissions: 36K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 *
 * 示例:
 *
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 *
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 *
 *
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#ifndef NULL
#define NULL nullptr
#endif

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {}
};

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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ret;
        if (root == nullptr) {
            return ret;
        }
        // 找到每一层的最右边的节点
        queue<TreeNode*> nodes;
        nodes.push(root);
        nodes.push(nullptr);

        bool newLine = true;
        while (!nodes.empty()) {
            TreeNode* node = nodes.front();
            nodes.pop();

            if (node == nullptr) {
                newLine = true;
                if (!nodes.empty()) {
                    nodes.push(nullptr);
                }
                continue;
            }

            if (newLine) {
                ret.push_back(node->val);
                newLine = false;
            }

            if (node->right != nullptr) {
                nodes.push(node->right);
            }
            if (node->left != nullptr) {
                nodes.push(node->left);
            }
        }

        return ret;
    }
};
// @lc code=end

int main()
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    t1.left  = &t2;
    t1.right = &t3;
    t2.right = &t5;
    t3.right = &t4;
    Solution so;
    auto ret = so.rightSideView(&t1);

    cout << "[";
    for (auto i : ret) {
        cout << i << ", ";
    }
    cout << "]" << endl;

    return 0;
}
