/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorderHelp(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    inorderHelp(root->left, result, index);
    result[(*index)++] = root->val;
    inorderHelp(root->right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));  
    *returnSize = 0;

    inorderHelp(root, result, returnSize);
    return result;
}
