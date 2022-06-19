class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[301];
        dp[0] = true;        
        for(int i = 1; i <= s.size(); i++){
            dp[i] = false;
            for(int j = 0; j < i; j++){
                if(!dp[j]) continue;
                string sub = s.substr(j,i-j);
                for(int k = 0; k < wordDict.size();k++){
                    if(wordDict[k].compare(sub) == 0) {
                        dp[i] = true;
                        break;
                    }
                }
                if(dp[i]) break;
            }
        }
        return dp[s.size()];
    }
};