
// Max Depth of Binary Tree - Leetcode Easy
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return 1 + max(leftDepth, rightDepth);
    }
};
// Path Sum - Leetcode easy
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || 
               hasPathSum(root->right, remainingSum);
    }
};

// Tree: Preorder Traversal - HackerRank easy
void preOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    
    cout << root->data << " ";
    
    preOrder(root->left);
    
    preOrder(root->right);
}



// Tree: Postorder Traversal - HacerkRank Easy
void postOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}