/*
 * @lc app=leetcode.cn id=1091 lang=c
 *
 * [1091] 二进制矩阵中的最短路径
 *
 * https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/description/
 *
 * algorithms
 * Medium (31.28%)
 * Likes:    34
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 18.7K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * 在一个 N × N 的方形网格中，每个单元格有两种状态：空（0）或者阻塞（1）。
 *
 * 一条从左上角到右下角、长度为 k 的畅通路径，由满足下述条件的单元格 C_1, C_2, ..., C_k 组成：
 *
 *
 * 相邻单元格 C_i 和 C_{i+1} 在八个方向之一上连通（此时，C_i 和 C_{i+1} 不同且共享边或角）
 * C_1 位于 (0, 0)（即，值为 grid[0][0]）
 * C_k 位于 (N-1, N-1)（即，值为 grid[N-1][N-1]）
 * 如果 C_i 位于 (r, c)，则 grid[r][c] 为空（即，grid[r][c] == 0）
 *
 *
 * 返回这条从左上角到右下角的最短畅通路径的长度。如果不存在这样的路径，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：[[0,1],[1,0]]
 *
 * 输出：2
 *
 *
 *
 * 示例 2：
 *
 * 输入：[[0,0,0],[1,1,0],[1,1,0]]
 *
 * 输出：4
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] 为 0 或 1
 *
 *
 */

// @lc code=start

#define QUE_SIZE 10000
int g_Que[QUE_SIZE];
int g_Front;
int g_End;

void QueInit()
{
    g_Front = 0;
    g_End   = 0;
}

void Push(int v)
{
    g_Que[g_End++] = v;
    g_End %= QUE_SIZE;
}

int Pop()
{
    int r = g_Que[g_Front++];
    g_Front %= QUE_SIZE;
    return r;
}

int IsEmpty()
{
    return g_Front == g_End;
}

#define JOIN(i, j) (((i) << 16) | (j))
#define GETI(v)    ((v) >> 16)
#define GETJ(v)    ((v)&0xffff)

const int DIRS[8][2] = {
    {-1, -1},
    {0, -1},
    {1, -1},
    {-1, 0},
    {1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
};

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize)
{
    int height = gridSize;
    int width  = gridColSize[0];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = -1;
            }
        }
    }
    if (grid[0][0] == -1) {
        return -1;
    }
    grid[0][0] = 1;
    QueInit();
    Push(JOIN(0, 0));

    while (!IsEmpty()) {
        int v = Pop();

        int i = GETI(v);
        int j = GETJ(v);
        if (i == height - 1 && j == width - 1) {
            break;
        }
        for (int k = 0; k < 8; k++) {
            int i1 = i + DIRS[k][0];
            int j1 = j + DIRS[k][1];
            if (i1 >= 0 && i1 < height && j1 >= 0 && j1 < width && grid[i1][j1] != -1) {
                if (grid[i1][j1] == 0 || grid[i1][j1] > grid[i][j] + 1) {
                    grid[i1][j1] = grid[i][j] + 1;
                    Push(JOIN(i1, j1));
                }
            }
        }
    }
    if (grid[height - 1][width - 1] == 0) {
        return -1;
    } else {
        return grid[height - 1][width - 1];
    }
}

// @lc code=end
