class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> hash_t;
        for(auto &it:numbers){
            hash_t[it]++;
        }
        vector<int> ans;
        for(int i=0; i<numbers.size(); i++){
            int temp=target - numbers[i];
            if((temp == numbers[i] && hash_t[temp]>1) || (temp!=numbers[i] && hash_t[temp]>0)){
                ans.push_back(i+1);
                ans.push_back((upper_bound(numbers.begin(),numbers.end(), temp)-numbers.begin()));
                break;
            }
        }
        return ans;
    }
};
