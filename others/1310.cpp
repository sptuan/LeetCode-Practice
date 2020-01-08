class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xor_temp(arr.size());
        int temp = 0;
        //cout<<(1 ^ 1) <<endl;
        for(int i=0; i<arr.size(); i++){
            temp = temp ^ arr[i];
            xor_temp[i] = temp;
            //cout<<temp<<endl;
        }

        vector<int> ans;

        for(int i=0; i<queries.size(); i++){
            if(queries[i][0]==0){
                ans.push_back(xor_temp[queries[i][1]]);
            }
            else{
                int temp_ans = xor_temp[queries[i][0]-1]^xor_temp[queries[i][1]];
                ans.push_back(temp_ans);
            }
        }
        return ans;
    }
};
