class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,bool> hash_t;
        for(auto &it:J){
            hash_t[it] = true;
        }
        int ans=0;
        for(auto &it:S){
            if(hash_t[it] == true){
                ans++;
            }
        }
        return ans;
    }
};
