class Solution {
public:
    int maximum69Number (int num) {
        int ans = 0;
        string temp;
        temp = to_string(num);
        for(int i=0; i<temp.size(); i++){
            if(temp[i] == '6'){
                temp[i] = '9';
                break;
            }
        }
        for(int i=0; i<temp.size(); i++){
            ans*=10;
            ans += temp[i]-'0';
        }
        return ans;
    }
};
