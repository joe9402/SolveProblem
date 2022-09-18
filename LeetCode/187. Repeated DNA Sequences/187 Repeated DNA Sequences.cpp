class Solution {
public:
    unordered_map<string, int> map;
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.length() < 10) return res;
        for(int i = 0; i < s.length()-9; i++){
            string subString = s.substr(i,10);
            map[subString]++;
        }
        for(auto const &pair : map){
            if(pair.second > 1)
                res.push_back(pair.first);
        }
        return res;
    }
};