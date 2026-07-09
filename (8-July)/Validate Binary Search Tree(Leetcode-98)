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
private:
    void inorder(TreeNode* root, vector<int> &tree){
        if(root == NULL) return;
        inorder(root->left, tree);
        tree.push_back(root->val);
        inorder(root->right, tree);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> tree;
        inorder(root, tree);
        for(int i=1; i<tree.size(); i++){
            if(tree[i-1] >= tree[i]) return false;
        }
        return true;
    }
};