// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char temp[4];
        int read_counter = 0;

        while(rest < n){
            read_counter = read4(temp);

            if(read_counter == 0) break;

            for(int i=0; i<read_counter; i++){
                buf_temp.push_back(*(temp+i));
            }
            rest += read_counter;
        }


        if(rest >= n){
            //string ans = buf_temp.substr(0,n);
            
            for(int i=0; i<n; i++){
                buf[i] = *(buf_temp.begin() + i);
            }
            buf_temp = buf_temp.substr(n,buf_temp.size());
            rest -= n;
            return n;
        }

        else{
             for(int i=0; i<rest; i++){
                buf[i] = *(buf_temp.begin() + i);
            }
            buf_temp.clear();
            int rest_temp = rest;
            rest = 0;
           return rest_temp;
        }
        

    }
private:
    string buf_temp;
    int rest = 0;
};
