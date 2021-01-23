class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> hash1;
        for(int i=0; i<B.size(); i++){
            hash1[B[i]] = i;
        }
        vector<int> ans;
        for(int i=0; i<A.size(); i++){
            ans.push_back(hash1[A[i]]);
        }
        return ans;
    }
};
