class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int ans = 0;
        
        while(c!=0 || b!=0 || a!=0){
            int a_bit = (a & 1);
            int b_bit = (b & 1);
            int c_bit = (c & 1);
            a = (a>>1);
            b = (b>>1);
            c = (c>>1);
            //cout<<"ABC_Bit: "<<a_bit<<b_bit<<c_bit<<endl;
            if(c_bit == 0){
                if(a_bit == 1){
                    //cout<<"c=0, a=1"<<endl;
                    ans++;
                }
                if(b_bit == 1){
                    //cout<<"c=0, b=1"<<endl;
                    ans++;
                }
            }
            else if(c_bit == 1){
                if(a_bit == 0 && b_bit == 0){
                    ans++;
                }
                
            }
        }
        return ans;
    }
};
