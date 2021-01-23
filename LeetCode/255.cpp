class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        this->preorder = preorder;
        return test(0,preorder.size());
    }
private:
    vector<int> preorder;
    bool test(int a, int b){
        if(b<=a) return true;
        int root_val = preorder[a];
        int i,j;
        for(i=a;i<b;i++){
            if(preorder[i]>root_val){
                break;
            }
        }
        int right_pos = i;
        /*
        for(i=a+1; i<right_pos; i++){
            if(preorder[i]>root_val) return false;
        }*/
        for(i=right_pos; i<b; i++){
            if(preorder[i]<root_val) return false;
        }
        if(test(a+1,right_pos)== false) return false;
        if(test(right_pos, b)==false) return false;

        return true;
    }
};
