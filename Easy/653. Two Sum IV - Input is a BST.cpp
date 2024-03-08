/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool search(int val, TreeNode *node, TreeNode *head)
    {
        if (node == NULL)
            return false;
        if (node->val == val && node!=head)
            return true;
        else if (val <= node->val)
            return search(val, node->left,head);
        else
            return search(val, node->right,head);

        return false;
    }
        
    bool ansTarget(TreeNode *root, int k, TreeNode *head)
    {
        if (root == NULL)
            return false;

        bool a = ansTarget(root->left, k, head);
        bool b = ansTarget(root->right, k, head);
        int diff = k - root->val;

        bool ans = search(diff,head,root);

        if (ans)
        {
            return true;
        }

        return a||b;
    }

    bool findTarget(TreeNode *root, int k)
    {
        return ansTarget(root,k,root);
    }
    
};