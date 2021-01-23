/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root==NULL) return ans;
        st.push(root);
        while(st.size()!=0){
            auto pointer = st.top();
            st.pop();
            ans.push_back(pointer->val);
            for(auto it=(pointer->children).end(); it!=(pointer->children).begin(); it--){
                st.push(*(it-1));
            }
        }
        return ans;
    }
private:
    stack<Node*> st;
    vector<int> ans;
};
