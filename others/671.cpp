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
    int findSecondMinimumValue(TreeNode* root) {
        DFS(root);
        if(hash_t.size()<2) return -1;
        auto it = (hash_t.begin());
        it++;
        return (*it).first;
    }
private:
    map<int, bool> hash_t;
    void DFS(TreeNode* root){
        if(root == NULL) return;
        hash_t[root->val] = true;
        DFS(root->left);
        DFS(root->right);
    }
};
