class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> maxLength1st;
        unordered_map<int, int> lengthCounter;
        int max_length = 0;
        for(int i=0; i<rectangles.size(); i++){
            if(rectangles[i][0]<rectangles[i][1]){
                maxLength1st.push_back(rectangles[i][0]);
                lengthCounter[rectangles[i][0]]++;
                if(rectangles[i][0]>max_length){
                    max_length = rectangles[i][0];
                }
            }
            else{
                maxLength1st.push_back(rectangles[i][1]);
                lengthCounter[rectangles[i][1]]++;
                if(rectangles[i][1]>max_length){
                    max_length = rectangles[i][1];
                }
            }
        }
        return lengthCounter[max_length];
    }
};