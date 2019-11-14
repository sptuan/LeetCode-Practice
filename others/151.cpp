class Solution {
public:
    string reverseWords(string s) {
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

        string ans;
        int counter = st.size();
        for(int i=0; i<counter; i++){
            ans+=(st.top());
            st.pop();
            if(i!=counter-1)
                ans+=" ";
        }
        return ans;
    }
};
