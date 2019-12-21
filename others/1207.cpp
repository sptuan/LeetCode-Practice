class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++){
            hash_t[arr[i]]++;
        } 
        for(auto &it:hash_t){
            if(hash_t2[it.second] > 0){
                return false;
            }
            hash_t2[it.second]++;
        }   
        return true;
    }
private:
    unordered_map<int,int> hash_t;
    unordered_map<int,int> hash_t2;
};
