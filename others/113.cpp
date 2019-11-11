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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return ans;
        this->target_sum = sum;
        DFS(root,0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    int target_sum = 0;
    vector<int> temp_q;
    void DFS(TreeNode* root, int sum){
        if(root == NULL){
            return;
        }
        
        temp_q.push_back(root->val);
        
        if((root->left == NULL) && (root->right == NULL)){
            //ans.push_back(temp_q);
            //cout<<sum + root->val<<endl;
            if(root->val + sum == target_sum){
                ans.push_back(temp_q);
            }
        }
        
        if(root->left!=NULL){
            DFS(root->left, sum+(root->val));
        }
        
        if(root->right!=NULL){
            DFS(root->right, sum+(root->val));
        }
        temp_q.pop_back();
        
        return;
    }
};
