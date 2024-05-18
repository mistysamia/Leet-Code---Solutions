bool isLeafNode(TreeNode* node)
{
    if(node->left == nullptr && node->right == nullptr)
        return true;
    return false;
}

TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if( !root )
        return nullptr;

    root-> left = removeLeafNodes(root-> left, target);
    root-> right = removeLeafNodes(root-> right, target);

    if(isLeafNode(root) && target == root->val)
        return nullptr;
    else
        return root;
}