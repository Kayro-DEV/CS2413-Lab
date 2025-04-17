/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traverse(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    result[(*index)++] = root->val;
    traverse(root->left, result, index);
    traverse(root->right, result, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));  // Up to 100 nodes
    *returnSize = 0;

    traverse(root, result, returnSize);
    return result;
}
