```cpp
/**
 * Core Idea: This solution performs a classic recursive in-order traversal of a binary tree,
 * collecting all node values into a vector in their in-order sequence.
 *
 * Time Complexity: O(N)
 * Each node in the tree is visited exactly once, where N is the number of nodes.
 *
 * Space Complexity: O(N)
 * O(N) for storing the result vector.
 * O(H) for the recursion call stack, where H is the height of the tree. In the worst case (a skewed tree), H can be N.
 * Thus, the total space complexity is O(N).
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
    void inorder(TreeNode* root,vector<int>& v){
        if (root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        return v;
    }
};
```