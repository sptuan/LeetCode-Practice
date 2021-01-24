class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> bucket_a(26,0);
        vector<int> bucket_b(26,0);
        int a_size = a.size();
        int b_size = b.size();
        
        for(int i=0; i<a.size(); i++){
            bucket_a[a[i]-'a']++;
        }
        for(int i=0; i<b.size(); i++){
            bucket_b[b[i]-'a']++;
        }
        vector<int> max_todo_a, min_todo_a, max_todo_b, min_todo_b;
        int counter_a = 0;
        int counter_b = 0;
        for(int i=0; i<26; i++){
            counter_a += bucket_a[i];
            min_todo_a.push_back(a_size - counter_a);
            max_todo_a.push_back(counter_a);
            
            counter_b += bucket_b[i];
            min_todo_b.push_back(b_size - counter_b);
            max_todo_b.push_back(counter_b);
        }
        
        int ans = INT_MAX;
        for(int i=0; i<26; i++){
            int temp_ans = min(min_todo_a[i] + max_todo_b[i], min_todo_b[i] + max_todo_a[i]);
            ans = min(ans, temp_ans);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a == b) return 0;
        return ans;
    }
};
