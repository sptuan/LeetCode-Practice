class Solution {
public:
    int minimumBoxes(int n) {
        long long sum = 0;
        long long last_sum = 0;
        int max_tower = 0;
        for(int i=0; i<n; i++){
            last_sum = sum; 
            sum += ((1+i)*i/2);
            if(sum>n){
                max_tower = i;
                break;
            }
        }
        long long rest = n - last_sum;
        
        int temp_x = 0;
        //int temp_sum = 0;
        while(1){
            if( ((1+temp_x)*temp_x/2) >= rest){
                break;
            }
            temp_x++;
        }
        
        return (1+max_tower-1)*(max_tower-1)/2 + temp_x;
    }
};
