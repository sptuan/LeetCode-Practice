class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string,vector<int>> hash_t;
        for(int i=0; i<words.size(); i++){
            hash_t[words[i]].push_back(i);
        }
        auto a1 = hash_t[word1];
        auto a2 = hash_t[word2];

        int min_temp=INT_MAX;
        for(int i=0; i<a1.size(); i++){
            for(int j=0; j<a2.size(); j++){
                int temp = abs(a1[i] - a2[j]);
                if(temp<min_temp){
                    min_temp = temp;
                }
            }
        }
        return min_temp;
        //int dis2 = words.size()-dis;

        //if(dis > dis2) return dis2;
        //else return dis;
    }
};
