class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> cache;
        unordered_map<int, bool> hash_t;
        for(int i=0; i<arr.size(); i++){
            if(hash_t[arr[i]]==false){
                cache.push_back(arr[i]);
                hash_t[arr[i]] = true;
            }
        }
        sort(cache.begin(), cache.end());
        unordered_map<int, int> rank_list;
        for(int i=0; i<cache.size(); i++){
            int size = cache.size();
            rank_list[cache[i]] = i + 1;
        }
        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            ans.push_back(rank_list[arr[i]]);
        }
        return ans;
    }
};
