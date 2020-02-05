class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0) return 0;
        stack<int> st;

        int curLength = 0;
        int maxLength = 0;
        int preLength = 0;

        unordered_map<int,int> hasht;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
                //preLength = 0;
                //curLength++;
            }
            if(s[i] == ')'){
                if(st.size()==0){
                    curLength = 0;
                    preLength = 0;
                }
                else{
                    int pre = st.top();
                    st.pop();

                    curLength = i - pre + 1 + hasht[pre-1];
                    maxLength = max(maxLength,curLength);
                    hasht[i] = curLength;
                }
            }
        }
    return maxLength;
    }
};
