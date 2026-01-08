/**
 * Core Idea:
 * This solution implements a standard recursive Preorder Traversal for a binary tree.
 * It processes the current node, then recursively traverses its left subtree, and finally its right subtree.
 * All visited node values are collected into a vector.
 *
 * Time Complexity: O(N)
 * Each of the N nodes in the tree is visited exactly once to add its value to the result vector.
 *
 * Space Complexity: O(N)
 * O(N) space is used for the output vector to store all N node values.
 * Additionally, O(H) space is used for the recursion call stack, where H is the height of the tree.
 * In the worst case (a skewed tree), H can be N, leading to an overall O(N) space complexity.
 */
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
    void preorder(TreeNode* root, vector<int>&v)
    {
        if (root==NULL) return;
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        preorder(root,v);
        return v;
    }
};