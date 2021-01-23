class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string temp;
        temp.push_back(counter);
        this->hash_t["http://tinyurl.com/" + temp] = longUrl;
        counter++;
        return "http://tinyurl.com/" + temp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return hash_t[shortUrl];
    }
private:
    unordered_map<string,string> hash_t;
    int counter = 0;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
