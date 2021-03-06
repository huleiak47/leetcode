/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (37.45%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 70.4K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 *
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 *
 * 示例:
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 *
 * 运行你的函数后，矩阵变为：
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 *
 * 解释:
 *a
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。
 *任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    int width;
    int height;

public:
    void solve(vector<vector<char>>& board)
    {
        if (board.size() <= 2 || board[0].size() <= 2) {
            return;
        }
        width  = board[0].size();
        height = board.size();

        // 从四条边上的O开始，进行深度优先搜索，遇到连接的O将其改为'*'
        for (int col = 0; col < width; ++col) {
            if (board[0][col] == 'O') {
                board[0][col] = '*';
                search(board, 0, col);
            }
            if (board[height - 1][col] == 'O') {
                board[height - 1][col] = '*';
                search(board, height - 1, col);
            }
        }
        for (int row = 0; row < height; ++row) {
            if (board[row][0] == 'O') {
                board[row][0] = '*';
                search(board, row, 0);
            }
            if (board[row][width - 1] == 'O') {
                board[row][width - 1] = '*';
                search(board, row, width - 1);
            }
        }

        // 最后扫一遍，将 * 改回 O，将O改为X
        for (auto& line : board) {
            for (auto& v : line) {
                if (v == '*') {
                    v = 'O';
                } else if (v == 'O') {
                    v = 'X';
                }
            }
        }
    }

    void search(vector<vector<char>>& board, int row, int col)
    {
        // 上边
        if (row > 0 && board[row - 1][col] == 'O') {
            board[row - 1][col] = '*';
            search(board, row - 1, col);
        }

        // 下边
        if (row + 1 < height && board[row + 1][col] == 'O') {
            board[row + 1][col] = '*';
            search(board, row + 1, col);
        }

        // 左边
        if (col > 0 && board[row][col - 1] == 'O') {
            board[row][col - 1] = '*';
            search(board, row, col - 1);
        }

        // 右边
        if (col + 1 < width && board[row][col + 1] == 'O') {
            board[row][col + 1] = '*';
            search(board, row, col + 1);
        }
    }
};
// @lc code=end
