/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    FindElements(TreeNode* root) {
        if(root == NULL) return;
        //root->val = 0;
        //hash_t[0] = true;
        DFS(root,0);
    }
    
    void DFS(TreeNode* root, int x){
        if(root == NULL) return;
        root->val = x;
        hash_t.insert(x);
        DFS(root->left, 2*x+1);
        DFS(root->right, 2*x+2);
    }
    bool find(int target) {
        return hash_t.count(target);
    }
private:
    unordered_set<int> hash_t;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
