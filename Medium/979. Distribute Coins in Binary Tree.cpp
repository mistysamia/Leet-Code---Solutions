int sum = 0;
int dfs(TreeNode* root) {
    if (!root)
        return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    sum += abs(left) + abs(right);
    return (root->val - 1) + left + right;
}

int distributeCoins(TreeNode* root) {
    dfs(root);
    return sum;
}