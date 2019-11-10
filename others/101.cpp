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
    bool isSymmetric(TreeNode* root) {
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        q2.push(root);
        while(q1.size()!=0 && q2.size()!=0){
            TreeNode* temp1 = q1.front();
            q1.pop();
            TreeNode* temp2 = q2.front();
            q2.pop();
            if(temp1 != NULL && temp2 != NULL){
                
                if(temp1->val != temp2->val) return false;
            }
            else if(temp1 == NULL && temp2 != NULL){
                return false;
            }
            else if(temp2 == NULL && temp1 != NULL){
                return false;
            }
            
            if(temp1 != NULL){
                q1.push(temp1->left);
                q1.push(temp1->right);
            }
            if(temp2 != NULL){
                q2.push(temp2->right);
                q2.push(temp2->left);
            }
        
        }
        return true;
    }
private:

};
