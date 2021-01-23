class Solution {
public:
    void reverseWords(vector<char>& s) {
        stack<string> st;
        string temp;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                if(temp.size()!=0){
                    st.push(temp);
                    temp.clear();
                }
            }
            else{
                temp.push_back(s[i]);
            }
        }
        if(temp.size()!=0){
            st.push(temp);
            temp.clear();
        }

        vector<char> ans;
        int counter = st.size();
        for(int i=0; i<counter; i++){
            auto temp_top = st.top();
            st.pop();

            for(auto &it:temp_top){
                ans.push_back(it);
            }

            if(i!=counter-1)
                ans.push_back(' ');
        }
        s = ans;
    }
};
