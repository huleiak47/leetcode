/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (62.27%)
 * Likes:    429
 * Dislikes: 0
 * Total Accepted:    74K
 * Total Submissions: 113.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *
 * 说明：每次只能向下或者向右移动一步。
 *
 * 示例:
 *
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 *
 *
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start

int min(int a, int b)
{
    return a < b ? a : b;
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int width  = grid[0].size();
        int height = grid.size();

        vector<int> sum(width);
        // sum[0] = grid[0][0];

        for (int i = 0; i < height; ++i) {
            // j = 0
            sum[0] += grid[i][0];
            for (int j = 1; j < width; ++j) {
                if (i == 0) {
                    sum[j] = sum[j - 1] + grid[i][j];
                } else {
                    sum[j] = min(sum[j], sum[j - 1]) + grid[i][j];
                }
            }
        }
        return sum[width - 1];
    }
};
// @lc code=end

int main()
{
    vector<vector<int>> arg {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    Solution so;

    cout << so.minPathSum(arg) << endl;

    return 0;
}
