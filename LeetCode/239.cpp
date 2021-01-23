class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if(nums.size()==0) return ans;
        int l = 0;
        int r = k;
        int max = INT_MIN;


        for(int i=0; i<=nums.size() - k; i++){
            if(i==0){
                for(int j=0; j<k; j++){
                    qpush(nums[j]);
                    
                }
                ans.push_back(qmax());
            }
            else{
                qpop(nums[i-1]);
                qpush(nums[i+k-1]);
                ans.push_back(qmax());
            }
        }
        return ans;
    }
private:
    deque<int> q;
    vector<int> ans;
    int qpush(int n){
        while(q.size()!=0 && q.back()<n){
            q.pop_back();
        }
        q.push_back(n);
        return 0;
    }
    int qpop(int n){
        if(q.size()!=0 && q.front()==n){
            q.pop_front();
        }
        return 0;
    }

    int qmax(){
        if(q.size()!=0)
            return q.front();
        else return -1;
    }
};
