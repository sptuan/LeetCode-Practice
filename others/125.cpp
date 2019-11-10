class Solution {
public:
    bool isPalindrome(string s) {
        string temps;
        for(auto &it:s){
            if(it>= 'a' && it <= 'z'){
                temps.push_back(it);
            }
            if(it>='A' && it <= 'Z'){
                temps.push_back(it - 'A' + 'a');
            }
            if(it>='0' && it <= '9'){
                temps.push_back(it);
            }
        }
        if(temps.size()==0) return true;
        for(int it = 0; it<temps.size(); it++){
            if(temps[it]!=temps[temps.size()-1-it]){
                return false;
            }
        }
        
        return true;
    }
};
