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

typedef struct Pos_ {
    struct Pos_* next;
    int i;
    int j;
} Pos;

typedef struct {
    Pos* first;
    Pos* last;
} PosQueue;

PosQueue* PosQueue_Create()
{
    PosQueue* queue = (PosQueue*)malloc(sizeof(PosQueue));
    queue->first    = NULL;
    queue->last     = NULL;
    return queue;
}

bool PosQueue_IsEmpty(const PosQueue* queue)
{
    return queue->first == NULL;
}

// the poped Pos* should be freed by user
Pos* PosQueue_Pop(PosQueue* queue)
{
    if (queue->first == NULL) {
        return NULL;
    }
    Pos* ret     = queue->first;
    queue->first = ret->next;
    if (queue->last == ret) {
        queue->last = NULL;
    }
    return ret;
}

void PosQueue_Push(PosQueue* queue, int i, int j)
{
    Pos* pos  = (Pos*)malloc(sizeof(Pos));
    pos->i    = i;
    pos->j    = j;
    pos->next = NULL;
    if (queue->first == NULL) {
        assert(queue->last == NULL);
        queue->first = pos;
        queue->last  = pos;
    } else {
        queue->last->next = pos;
        queue->last       = pos;
    }
}

void PosQueue_Release(PosQueue* queue)
{
    Pos* pos = queue->first;
    while (pos != NULL) {
        Pos* temp = pos->next;
        free(pos);
        pos = temp;
    }
    free(queue);
}

void Search(int** sizes, int height, int width)
{
    PosQueue* queue = PosQueue_Create();

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (sizes[i][j] == 0) {
                PosQueue_Push(queue, i, j);
            }
        }
    }
    PosQueue_Push(queue, -1, -1);

    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!PosQueue_IsEmpty(queue)) {
        Pos* pos = PosQueue_Pop(queue);
        if (pos->i == -1) {
            if (PosQueue_IsEmpty(queue)) {
                free(pos);
                break;
            }
            PosQueue_Push(queue, -1, -1);
            free(pos);
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int _i = pos->i + dir[i][0];
            int _j = pos->j + dir[i][1];
            if (_i >= 0 && _i < height && _j >= 0 && _j < width) {
                if (sizes[pos->i][pos->j] + 1 < sizes[_i][_j]) {
                    sizes[_i][_j] = sizes[pos->i][pos->j] + 1; // update this cell
                    PosQueue_Push(queue, _i, _j);              // should update it's neighbors
                }
            }
        }

        free(pos);
    }
    PosQueue_Release(queue);
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
            sizes[i][j] = matrix[i][j] != 0 ? INT_MAX : 0;
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
