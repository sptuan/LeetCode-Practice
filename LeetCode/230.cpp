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
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inorder(root);

        return ans[k-1];
    }
private:
    vector<int> ans;
    int k;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        
        inorder(root->left);
        ans.push_back(root->val);
        if(ans.size()>=k) return;

        inorder(root->right);
        return;
    }
};
