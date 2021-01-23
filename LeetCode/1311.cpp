unordered_map<string,int> global_times;
    bool cmp(string a, string b){
        if(global_times[a]!=global_times[b]){
            return global_times[a]<global_times[b];
        }
        else{
            return a<b;
        }
        return 0;
    }

class Solution {
public:
    //watch times
    unordered_map<string,int> times;

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {

        //BFS
        queue<int> q_id;
        queue<int> q_depth;

        q_id.push(id);
        q_depth.push(0);

        unordered_map<int, bool> hash_t;
        vector<int> target_id;
        hash_t[id] = true;
        while(q_id.size()!=0){
            int temp_id = q_id.front();
            int temp_depth = q_depth.front();
            q_id.pop();
            q_depth.pop();

            if(temp_depth>level) continue;
            //hash_t[temp_id] = true;

            if(temp_depth == level){
                target_id.push_back(temp_id);
            }

            for(int i=0; i<friends[temp_id].size(); i++){
                if(hash_t[friends[temp_id][i]] == false){
                    q_id.push(friends[temp_id][i]);
                    q_depth.push(temp_depth+1);
                    hash_t[friends[temp_id][i]] = true;
                }
            }

        }

        vector<string> target_video;
        unordered_map<string, bool> watched;

        for(int i=0; i<target_id.size(); i++){
            for(int j=0; j<watchedVideos[target_id[i]].size(); j++){
                if(watched[watchedVideos[target_id[i]][j]] == false){
                    target_video.push_back(watchedVideos[target_id[i]][j]);
                    watched[watchedVideos[target_id[i]][j]] = true;
                }

                times[watchedVideos[target_id[i]][j]]++;
            }
        }
        global_times = times;
        sort(target_video.begin(), target_video.end(), cmp);
        return target_video;
    }
};

