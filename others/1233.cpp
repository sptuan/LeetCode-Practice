class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        for(int i=0; i<folder.size(); i++){
            hash_t[folder[i]] = true;;
        }
        vector<string> ans;
        for(int i=0; i<folder.size(); i++){
            bool result = check(folder[i]);
            if(result == true){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
private:
    unordered_map<string, bool> hash_t;
    bool check(string &folder_string){
            //find last '/'
            //cout<<"Checking "<<folder_string<<endl;
            int f;
            for(f = folder_string.size()-1; f!=-1; f--){
                if(folder_string[f] == '/') break;
            }
            //cout<<"F: "<<f<<endl;
            //check father str hash_t
            /*
            string father;
            for(int f_i = 0; f_i <= f; f_i++){
                father.push_back()
            }
            */
            if(f==0){
                return true;
            }
            string father = folder_string.substr(0,f);
            if(hash_t[father] == true){
                return false;
            }
           return check(father);

    }
};
