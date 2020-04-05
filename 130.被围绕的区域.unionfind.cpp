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
    {}
};

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
        // 这里使用BFS搜索算法
        queue<Pos> q;
        q.push(Pos(row, col));

        while (!q.empty()) {
            Pos pos = q.front();
            q.pop();

            // 上边
            if (pos.row > 0 && board[pos.row - 1][pos.col] == 'O') {
                board[pos.row - 1][pos.col] = '*';
                q.push(Pos(pos.row - 1, pos.col));
            }

            // 下边
            if (pos.row + 1 < height && board[pos.row + 1][pos.col] == 'O') {
                board[pos.row + 1][pos.col] = '*';
                q.push(Pos(pos.row + 1, pos.col));
            }

            // 左边
            if (pos.col > 0 && board[pos.row][pos.col - 1] == 'O') {
                board[pos.row][pos.col - 1] = '*';
                q.push(Pos(pos.row, pos.col - 1));
            }

            // 右边
            if (pos.col + 1 < width && board[pos.row][pos.col + 1] == 'O') {
                board[pos.row][pos.col + 1] = '*';
                q.push(Pos(pos.row, pos.col + 1));
            }
        }
    }
};
// @lc code=end
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
    {}
};

class Solution {
private:
    int width;
    int height;

    vector<int> nodes;

public:
    int Find(Pos& p)
    {
        int p1   = p.row * height + p.col;
        int root = nodes[p1];
        while (p1 != root) {
            p1   = root;
            root = nodes[p1];
        }
        return root;
    }

    void Connect(Pos& p, Pos& q)
    {
        int proot = Find(p);
        int qroot = Find(q);
        if (proot != qroot) {
            nodes[proot] = qroot;
        }
    }

    bool IsConnect(Pos& p, Pos& q)
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
        for (int i = 0; i < nodes.size(); ++i) {
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
