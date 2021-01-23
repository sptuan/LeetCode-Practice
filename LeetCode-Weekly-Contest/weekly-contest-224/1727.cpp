class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<int> conti_seg_left,conti_seg_right;
        // speical for line
        int line_counter = 0;
        int total_counter = 0;
        if(matrix.size() == 1){
            for(int i=0; i<matrix[0].size(); i++){
                if(matrix[0][i] == 1){
                    line_counter++;
                }
                //cout<<line_counter<<endl;
            }
            return line_counter;
        }
        
        if(matrix[0].size() == 1){
            for(int i=0; i<matrix.size(); i++){
                if(matrix[i][0] == 1){
                    line_counter++;
                }
                //cout<<line_counter<<endl;
            }
            return line_counter;
        }
        // common
        else{
            for(int i=0; i<matrix[0].size(); i++){
                int temp_l = 0;
                int temp_r = 0;
                if(matrix[0][i] == 1){
                    conti_seg_left.push_back(0);
                    //total
                    total_counter++;
                }
                for(int j=1; j<matrix.size(); j++){
                    if(matrix[j][i] == 0 && matrix[j-1][i] == 1){
                        conti_seg_right.push_back(j-1);
                    }
                    if(matrix[j][i] == 1 && matrix[j-1][i] == 0){
                        conti_seg_left.push_back(j);
                    }
                    
                    //total
                    if(matrix[j][i] == 1){
                        total_counter++;
                    }
                }
                if(matrix[matrix.size()-1][i] == 1){
                    conti_seg_right.push_back(matrix.size()-1);
                }
            }
        }
        
        int max_size = 0;
        
        if(total_counter == (matrix.size() * matrix[0].size()))
            return total_counter;
        
        for(int L=0; L<matrix.size(); L++){
            for(int R=L; R<matrix.size(); R++){
                int temp_counter = 0;
                for(int s=0; s<conti_seg_left.size(); s++){
                    if(conti_seg_left[s]<=L && conti_seg_right[s]>=R)
                        temp_counter++;
                }
                int temp_size = (R-L+1) * temp_counter;
                if(temp_size > max_size){
                    max_size = temp_size;
                }
            }
        }
        
        return max_size;
    }
};