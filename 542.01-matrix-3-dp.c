/*
 * @lc app=leetcode.cn id=542 lang=c
 *
 * [542] 01 矩阵
 *
 * https://leetcode-cn.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (34.44%)
 * Likes:    165
 * Dislikes: 0
 * Total Accepted:    13.1K
 * Total Submissions: 34.3K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
 *
 * 两个相邻元素间的距离为 1 。
 *
 * 示例 1:
 * 输入:
 *
 *
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 *
 * 输出:
 *
 *
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 *
 * 示例 2:
 * 输入:
 *
 *
 * 0 0 0
 * 0 1 0
 * 1 1 1
 *
 *
 * 输出:
 *
 *
 * 0 0 0
 * 0 1 0
 * 1 2 1
 *
 *
 * 注意:
 *
 *
 * 给定矩阵的元素个数不超过 10000。
 * 给定矩阵中至少有一个元素是 0。
 * 矩阵中的元素只在四个方向上相邻: 上、下、左、右。
 *
 *
 */

// @lc code=start

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <assert.h>

int Min(int a, int b)
{
    return a < b ? a : b;
}

void Search(int** sizes, int height, int width)
{
    // search from top-left to bottom-right
    // first line
    for (int i = 1; i < width; ++i) {
        sizes[0][i] = Min(sizes[0][i], sizes[0][i - 1] + 1);
    }
    // other lines
    for (int i = 1; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j == 0) {
                sizes[i][j] = Min(sizes[i][j], sizes[i - 1][j] + 1);
            } else {
                sizes[i][j] = Min(sizes[i][j], Min(sizes[i - 1][j] + 1, sizes[i][j - 1] + 1));
            }
        }
    }

    // search from bottom-right to top-left
    // first line
    for (int i = width - 2; i >= 0; --i) {
        sizes[height - 1][i] = Min(sizes[height - 1][i], sizes[height - 1][i + 1] + 1);
    }
    // other lines
    for (int i = height - 2; i >= 0; --i) {
        for (int j = width - 1; j >= 0; --j) {
            if (j == width - 1) {
                sizes[i][j] = Min(sizes[i][j], sizes[i + 1][j] + 1);
            } else {
                sizes[i][j] = Min(sizes[i][j], Min(sizes[i + 1][j] + 1, sizes[i][j + 1] + 1));
            }
        }
    }
}

int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    int height = matrixSize;
    int width  = matrixColSize[0];

    int** sizes        = (int**)malloc(height * sizeof(int*));
    *returnColumnSizes = (int*)malloc(height * sizeof(int));
    *returnSize        = height;
    for (int i = 0; i < height; ++i) {
        sizes[i] = (int*)malloc(width * sizeof(int*));
        memset(sizes[i], 0, width * sizeof(int*));
        (*returnColumnSizes)[i] = width;
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            sizes[i][j] = matrix[i][j] != 0 ? INT_MAX / 2 : 0;
        }
    }
    Search(sizes, height, width);

    return sizes;
}

// @lc code=end

int line0[] = {0, 0, 0};
int line1[] = {0, 1, 0};
int line2[] = {1, 1, 1};

int* matrix[] = {line0, line1, line2};
int colSize[] = {3, 3, 3};

int main()
{
    int returnSize;
    int* returnColSize;
    int** ret = updateMatrix(matrix, 3, colSize, &returnSize, &returnColSize);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d, ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}
