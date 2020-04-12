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
#include <queue>

using namespace std;

// @lc code=start
struct Pos {
    int row;
    int col;
    Pos(int r, int c) : row(r), col(c)
    { }
};

class Solution {
private:
    int width;
    int height;

    vector<int> nodes;

public:
    int Find(const Pos& p)
    {
        int p1   = p.row * height + p.col;
        int root = nodes[p1];
        while (p1 != root) {
            p1   = root;
            root = nodes[p1];
        }
        return root;
    }

    void Connect(const Pos& p, const Pos& q)
    {
        int proot = Find(p);
        int qroot = Find(q);
        if (proot != qroot) {
            nodes[proot] = qroot;
        }
    }

    bool IsConnect(const Pos& p, const Pos& q)
    {
        return Find(p) == Find(q);
    }

    void solve(vector<vector<char>>& board)
    {
        if (board.size() <= 2 || board[0].size() <= 2) {
            return;
        }
        width  = board[0].size();
        height = board.size();
        nodes  = vector<int>(width * height + 1);
        for (int i = 0; i < (int)nodes.size(); ++i) {
            nodes[i] = i;
        }

        Pos edge(width, height); // 这个点不在矩阵之中，用来表示边界之外

        // 从四条边上开始，找到O点，连接到边界之外
        for (int col = 0; col < width; ++col) {
            if (board[0][col] == 'O') {
                Connect(Pos(0, col), edge);
            }
            if (board[height - 1][col] == 'O') {
                Connect(Pos(height - 1, col), edge);
            }
        }
        for (int row = 0; row < height; ++row) {
            if (board[row][0] == 'O') {
                Connect(Pos(row, 0), edge);
            }
            if (board[row][width - 1] == 'O') {
                Connect(Pos(row, width - 1), edge);
            }
        }

        // 扫描内部点，与四周的O连接
        for (int row = 1; row < height - 1; ++row) {
            for (int col = 1; col < width - 1; ++col) {
                if (board[row][col] == 'O') {
                    if (board[row - 1][col] == 'O') {
                        Connect(Pos(row, col), Pos(row - 1, col));
                    }
                    if (board[row + 1][col] == 'O') {
                        Connect(Pos(row, col), Pos(row + 1, col));
                    }
                    if (board[row][col - 1] == 'O') {
                        Connect(Pos(row, col), Pos(row, col - 1));
                    }
                    if (board[row][col + 1] == 'O') {
                        Connect(Pos(row, col), Pos(row, col + 1));
                    }
                }
            }
        }

        // 最后扫一遍，与 edge 不连通的改为X
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (board[row][col] == 'O' && !IsConnect(Pos(row, col), edge)) {
                    board[row][col] = 'X';
                }
            }
        }
    }
};
// @lc code=end

#include <iostream>
using namespace std;

int main()
{
    Solution so;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    so.solve(board);
    for (auto& vec : board) {
        for (auto& c : vec) {
            cout << c << ",";
        }
        cout << endl;
    }
    return 0;
}
