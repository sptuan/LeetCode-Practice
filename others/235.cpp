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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        p_val  = p->val;
        q_val = q->val;
        DFS(root);

        TreeNode* ans;
        for(int i=0; i<seq_p.size() && i<seq_q.size(); i++){
            if((seq_p[i] -> val) == (seq_q[i]->val)){
                ans = seq_p[i];
            }
            else{
                break;
            }
        }

        return ans;
    }
private:
    vector<TreeNode*> seq;
    vector<TreeNode*> seq_p;
    vector<TreeNode*> seq_q;
    int p_val;
    int q_val;

    int p_flag = 0;
    int q_flag = 0;

    void DFS(TreeNode* root){
        if(root == NULL) return;
        

        if(p_flag == 0 || q_flag == 0){
                    seq.push_back(root);

                    if(root->val == p_val){
                        seq_p = seq;
                        p_flag = 1;
                    }
                    if(root->val == q_val){
                        seq_q = seq;
                        q_flag = 1;
                    }

                    DFS(root->left);
                    DFS(root->right);
                    seq.pop_back();
        }
        else{
            return;
        }
        

        return;
    }
};
