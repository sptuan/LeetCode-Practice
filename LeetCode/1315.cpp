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
    int sumEvenGrandparent(TreeNode* root) {
        DFS(root, buffer);
        return ans;
    }
private:
    vector<int> buffer;
    int ans = 0;
    void DFS(TreeNode* root, vector<int> buffer){
        if(root == NULL) return;
        cout<<buffer.size()-2<<endl;
        if(buffer.size() >= 2){
            //cout<<"BUFFER"<<endl;
            if(*(buffer.end()-2) % 2 == 0){
                ans += root->val;
            }
        }
        buffer.push_back(root->val);
        DFS(root->left, buffer);
        DFS(root->right, buffer);
        return;
    }
};
