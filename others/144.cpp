/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return ans;
    }
private:
    vector<int> ans;
    void pre(TreeNode* root){
        if(root==NULL) return;
        ans.push_back(root->val);
        pre(root->left);
        pre(root->right);
        return;
    }
};
