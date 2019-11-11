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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if(root==NULL) return {};
        q.push(make_pair(root,0));
        
        vector<int> ans;
        int level_counter = -1;
        
        while(q.size()!=0){
            auto temp = q.front();
            q.pop();
            int level = temp.second;
            TreeNode* node = temp.first; 
            if(level>level_counter){
                ans.push_back(node->val);
                level_counter = level;
            }
            
            if(node->right!=NULL){
                q.push(make_pair(node->right, level+1));
            }
            if(node->left!=NULL){
                q.push(make_pair(node->left, level+1));
            }

            
        }
        return ans;
    }
};
