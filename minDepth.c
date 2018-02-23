//
// Created by cyq7on on 18-2-23.
//

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

#include <wchar.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

};

int minDepth(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if (root->left && root->right) {
        return left > right ? left + 1 : right + 1;
    } else {
        return left < right ? left + 1 : right + 1;
    }
}