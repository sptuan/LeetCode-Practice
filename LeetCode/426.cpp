/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        //Node head;
        if(root == NULL) return NULL;

        inorder(root);


        Node* pre = *(inordered.end() - 1);

        
        for(auto it=inordered.begin(); it!=inordered.end(); it++){
            (*it)->left = pre;
            pre->right = *it;
            pre = *it;
        }
        (*(inordered.begin()))->left = *(inordered.end() - 1);
        (*(inordered.end() - 1))->right = *(inordered.begin());

        return *(inordered.begin());
    }
private:
    vector<Node*> inordered;
    void inorder(Node* root){
        if(root == NULL) return;
        inorder(root->left);
        inordered.push_back(root);
        inorder(root->right);
        return;
    }
};
