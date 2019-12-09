class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        if(height.size()<3) return 0;
        vector<int> max_l;
        int temp_max= -1;
        for(int i=0; i<height.size(); i++){
            if(height[i]>temp_max){
                temp_max = height[i];
            }
            max_l.push_back(temp_max);
            //cout<<"Max L "<<temp_max<<endl;
        }
        vector<int> max_r;
        temp_max= -1;
        for(int i=height.size()-1; i>=0; i--){
            if(height[i]>temp_max){
                temp_max = height[i];
            }
            max_r.push_back(temp_max);
            //cout<<"Max R "<<temp_max<<endl;
        }


        for(int i=1; i<height.size()-1; i++){
            int temp_ans = min(max_l[i-1], max_r[height.size() - i - 1]) - height[i];
            if(temp_ans>0){
                ans+=temp_ans;
            }
        }

        return ans;
    }
};
