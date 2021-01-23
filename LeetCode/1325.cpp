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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode pre(0);
        this->target = target;
        pre.left = root;
        do{
            flag = 1;
            DFS(root, &pre, 0);
        }while(flag == 0 && pre.left != NULL);
        return pre.left;
    }
private:
    int flag = 1;
    int target = 0;
    void DFS(TreeNode* root, TreeNode* pre, int lr){
        //lr-0: left lr-1: right
        if(root == NULL) return;
        if(root->right == NULL && root->left == NULL && root->val == target){
            if(lr == 0){
                pre->left = NULL;
            }
            if(lr == 1){
                pre->right = NULL;
            }
            flag = 0;
            return;
        }
        DFS(root->left, root, 0);
        DFS(root->right, root, 1);
        return;
    }
};
